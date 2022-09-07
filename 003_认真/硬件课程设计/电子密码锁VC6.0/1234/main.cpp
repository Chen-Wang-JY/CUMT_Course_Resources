#include<stdio.h>
#include<conio.h>
#include "ApiExUsb.h"
#include<iostream>
#include<windows.h>
#pragma comment(lib,"ApiExUsb.lib")
#pragma warning(disable:4996)

#define PORT_A 0x280
#define PORT_B 0x281
#define PORT_C 0x282
#define PORT_CTL 0x283

byte encode();
void toBinary(byte data);


void init() {
	PortWriteByte(PORT_CTL, 0x82); //10000010;
}

void test() {
	byte data;
	if (!PortReadByte(PORT_B, &data)) {
		std::cout << "读错误" << std::endl;
		return;
		
	}
	if (!PortWriteByte(PORT_A, data)) {
		std::cout << "写错误" << std::endl;
		return;
	}
}

void keyBoard()
{
	byte data;	//寄存器

	//向所有行送0
	PortWriteByte(PORT_C, 0x00);
	//读列，查看所有键是否松开
	while (1) {
		if (!PortReadByte(PORT_B, &data)) {
			printf("QQQQ");
		}
		//读取四根列线，全为高电位则所有键松开。
		data = data & 0x0f;
		if (data != 0x0f)		//有键按下则进入循环
			continue;
		//判断是否有键按下
		while (1) {

			if (!PortReadByte(PORT_B, &data)) {
				printf("读数据错误\n");
			}
			data = data & 0x0f;
			if (data != 0x0f)
				break;
		}
		//有键按下，延迟20ms，消除抖动
		Sleep(20);
		//再查列，是否仍有键按下
		if (!PortReadByte(PORT_B, &data)) {
			printf("第二次错误\n");
		}
		data = data & 0x0f;
		if (data == 0x0f)		//无键按下则重新读列
			continue;
		else {
			break;				//有键按下则退出大循环
		}
	}
	//仍有键按下，确定键位
	byte location = 0xFE;
	while (1) {

		//使一行变为低电平
		PortWriteByte(PORT_C, location);
		//读入键盘状态
		PortReadByte(PORT_B, &data);
		//只截取列值
		data = data & 0x0F;
		//是否均为1？
		if (data == 0x0F) {
			//均为1，不是该行按键按下
			location = location << 1;			//左移，判断下一行
			location = location + 1;
			continue;
		}
		else {
			//不均为1，该行按键被按下
			//while(1) printf("编码！！！\n"); 
			encode();
			break;
		}
	}
}

//键盘编码函数01110111
byte encode() {
	byte data;
	byte table[16] = { 0x77, 0x7B, 0x7D, 0x7E, 0xB7, 0xBB, 0xBD, 0xBE,
					  0xD7, 0xDB, 0xDD, 0xDE, 0xE7, 0xEB, 0xED, 0xEE };
	PortReadByte(PORT_B, &data);
	byte high = (data & 0xF0) >> 4;
	byte low  = data & 0x0F;
	printf("%d %d %d\n", data, high, low);
	for (int i = 0; i < 16; i++) {
		if (table[i] == data) {
			PortWriteByte(PORT_A, data);
			return data;
		}
	}
	return 0x00;
}

int main()
{
	byte data;
	if (!Startup())
	{
		printf("ERROR: Open Device Error!\n");
		return 0;
	}
	printf("Begin!\n");
	init();
	while (!kbhit())
	{
		keyBoard();
	}
	printf("Press any key to exit!\n");
	while (!kbhit());
	Cleanup();
	return 0;
}