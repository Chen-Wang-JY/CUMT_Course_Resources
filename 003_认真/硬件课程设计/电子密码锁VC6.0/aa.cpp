#include <stdio.h>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <iostream>
#include "ApiExUsb.h"
#pragma comment(lib,"ApiExUsb.lib")
#pragma warning(disable:4996)

#define PORT_A 0x280
#define PORT_B 0x281
#define PORT_C 0x282
#define PORT_CTL 0x283
#define PORT_273 0x290

using namespace std;

vector<int> PASSWORD;
vector<int> password;
vector<int> customsCode;

//开始时读一次数据
void test(){
	byte data;
	if(!PortReadByte(PORT_B, &data)){
		while (!kbhit()) printf("读数据错误\n");
	}
}
//测试
void dispCurrentPassword();

//初始化
void init();
void formatDisp(byte data);

/*=================LCD部分========================*/
//向LCD写指令
void cmdSetup();
//向LCD写数据
void dataSetup();
//LCD清屏
void LCDClear();
//LCD初始化：功能设定（基本指令集合）
void LCDInit();
//显示
void LCDDispFirstRow();
void LCDDispSecondRow();
void LCDDispSecondRow_1();
void LCDDispSuccess();
void LCDDispDeafuat();
void LCDDispSetting();
void LCDWarning();
//密码动态显示
void LCDDispThirdRow(byte data, byte currentLoc, bool flag=true);
//重写密码
byte reWritePassword();
//清除指定位置内容
void LCDDelete(byte currentLoc);
/*=================键盘部分========================*/
//键盘编码函数
byte encode();
//接受一次按键
byte keyBoard();
/*=================密码部分========================*/
void setCustomsCode();
void readPassword();
bool passwordRight();
void savePassword();
int Go(int num)；
int Ret(int num)；
/*=================继电器部分========================*/
void deviceStart();
/*=================声光报警部分========================*/
void light_sound_warning();

int warning;


int main() {
	warning = 3;
	byte table[16] = { 0x77, 0x7B, 0x7D, 0x7E, 0xB7, 0xBB, 0xBD, 0xBE,
					  0xD7, 0xDB, 0xDD, 0xDE, 0xE7, 0xEB, 0xED, 0xEE };


	byte data;
	if (!Startup())
	{
		printf("ERROR: Open Device Error!\n");
		return 0;
	}
	init();
	test();
	

	LCDDispFirstRow();	
	LCDDispSecondRow();

	byte currentLoc = 0x88;		//0x89H ~ 0x8EH	 6个数 +5
	
	readPassword();
	setCustomsCode();

	byte lastNum = 0xDD;
	bool r = false;
	vector<int> temp;
	/*
	当前模式
	1——解锁
	2——设定密码
    */
	int state = 1;
	while(!kbhit()){
		byte num = keyBoard();
		//A 退格
		if(num == 0xDD){
			LCDDelete(currentLoc);
			if(currentLoc != 0x88){
				currentLoc--;
			}
			if(password.size() != 0)
				lastNum = table[password[password.size() - 1]];
		}
		//E 确认密码
		else if(num ==  0xEE){
			//state==1   解锁
			if(state == 1){
				bool flag = passwordRight();
				if(flag){
					printf("密码正确，开锁成功！\n");
					warning = 3;
					deviceStart();
					LCDDispSuccess();
					Sleep(2000);
					LCDDispSecondRow();
					currentLoc = reWritePassword();
				}
				else{
					printf("密码错误！\n");
					dispCurrentPassword();
					light_sound_warning();
					//LCDDispDeafuat();
					//Sleep(2000);
					LCDDispSecondRow();
				    reWritePassword();
				}
				//if(currentLoc >= 0x89 && currentLoc <= 0x8E)
				//	LCDDispThirdRow(lastNum, currentLoc, false);
				currentLoc = 0x88;
			}
			//state==2  设定
			else if(state == 2){
				printf("设定\n");
				
				if(!r && password.size() == 6){
					for(int i=0; i<password.size(); i++)
						temp.push_back(password[i]);
					password.clear();
					reWritePassword();
					r = true;
					currentLoc = 0x88;
				}
				else if(r && password.size() == 6)
				{
					bool rr = true;
					printf("%d %d\n", password.size(), temp.size());
					for(int i = 0; i < 6; i++){
						if(temp[i] != password[i])
							rr = false;
					}
					if(!rr)
					{
						printf("两次密码不一致！\n");
						reWritePassword();
						currentLoc = 0x88;
						continue;
					}
					dispCurrentPassword();
					savePassword();
					readPassword();
					printf("设置成功！\n");
					LCDDispSetting();
					Sleep(2000);
					LCDDispSecondRow();
				    reWritePassword();
					currentLoc = 0x88;
					temp.clear();
					r = false;
					state = 1;
				}
			}
		}
		//C 切换模式——设定/输入密码
		else if(num == 0xE7){
			if(state == 1){
				LCDDispSecondRow_1();
				state = 2;
			}
			else if(state == 2){
				LCDDispSecondRow();
				state = 1;
			}
			
			if(currentLoc >= 0x89 && currentLoc <= 0x8E)
					LCDDispThirdRow(lastNum, currentLoc, false);
		}
		//显示数字
		else
		{
			if(currentLoc < 0x8E)
				currentLoc++;
			printf("currentLoc:%d\n", currentLoc);
			LCDDispThirdRow(num, currentLoc);
			lastNum = num;
		}
	}

	printf("按任意键退出\n");
	while(!kbhit());
    return 0;
}

void init(){
	//8255
	PortWriteByte(PORT_CTL, 0x82);		//10000010	
	//LCD
	LCDInit();
	//273
	PortWriteByte(PORT_273, 0x00);
}
void formatDisp(byte data){
	byte low = data & 0x0F;
	byte high = data & 0xF0;
	printf("data:%d   high:%d    low:%d\n", data, high>>4, low);
}



/*=================LCD部分========================*/
void cmdSetup() {
    /*
    8255C端口：
    PC5---E
    PC6---R/W        0
    PC7---RS(D/I)    0
    */
    PortWriteByte(PORT_C, 0x00);
    Sleep(5);
    PortWriteByte(PORT_C, 0x20);       //0010 0000
    Sleep(5);
    PortWriteByte(PORT_C, 0x00);       //0000 0000 
	Sleep(5);
}

void dataSetup() {
    /*
    8255C端口：
    PC5---E
    PC6---R/W        0
    PC7---RS(D/I)    1
    */
    PortWriteByte(PORT_C, 0x80);       //1000 0000
    Sleep(5);
    PortWriteByte(PORT_C, 0xA0);       //1010 0000
    Sleep(5);
    PortWriteByte(PORT_C, 0x80);       //1000 0000
	Sleep(5);
}

void LCDClear() {
    //基本指令集——1.清除显示
    //将指令写入LCD数据口
    PortWriteByte(PORT_A, 0x01);       //0000 0001
    cmdSetup();
}

void LCDInit() {
	LCDClear();
    //基本指令集——6.功能设定
    PortWriteByte(PORT_A, 0x30);       //0011 0000
    cmdSetup();
	PortWriteByte(PORT_A, 0x0C);	   //显示游标啥的
	cmdSetup();
}

void LCDDispFirstRow() {

    //第一行的汉字编码
    byte table[8][2] = {
        0xA1, 0xA0,
        0xA1, 0xBE,
        0xB3, 0xBF,
        0xA1, 0xBF,
        0xB5, 0xE7,
        0xD7, 0xD3,
        0xCB, 0xF8,
        0xA1, 0xA0
    };

    //第一行基地址
    byte baseAddr = 0x80;

    //显示第一行8个汉字
    for (int i = 0; i < 8; i++) {

        //调用CMDSetup，设定DDRAM的地址
        PortWriteByte(PORT_A, baseAddr);       //0x90是第一行首地址
        cmdSetup();
        baseAddr = baseAddr + 1;
        //送高字节
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //送低字节
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
    }
}

void LCDDispSecondRow(){

    //第二行的汉字编码
    byte table[8][2] = {
        0xC7, 0xEB,
        0xCA, 0xE4,
        0xC8, 0xEB,
        0xC3, 0xDC,
        0xC2, 0xEB,
        0xA3, 0xBA,
        0xA1, 0xA0,
        0xA1, 0xA0
    };

    //第二行基地址
    byte baseAddr = 0x90;

    //显示第二行8个汉字
    for (int i = 0; i < 8; i++) {

        //调用CMDSetup，设定DDRAM的地址
        PortWriteByte(PORT_A, baseAddr);       //0x90是第一行首地址
        cmdSetup();
        baseAddr = baseAddr + 1;
        //送高字节
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //送低字节
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
    }
}

void LCDDispSecondRow_1(){
	//第二行的汉字编码
    byte table[8][2] = {
        0xC9, 0xE8,
        0xD6, 0xC3,
        0xC3, 0xDC,
        0xC2, 0xEB,
        0xA3, 0xBA,
        0xA1, 0xA0,
        0xA1, 0xA0,
        0xA1, 0xA0
    };

    //第二行基地址
    byte baseAddr = 0x90;

    //显示第二行8个汉字
    for (int i = 0; i < 8; i++) {

        //调用CMDSetup，设定DDRAM的地址
        PortWriteByte(PORT_A, baseAddr);       //0x90是第一行首地址
        cmdSetup();
        baseAddr = baseAddr + 1;
        //送高字节
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //送低字节
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
    }
}

void LCDDelete(byte currentLoc){
	PortWriteByte(PORT_A, currentLoc);
	cmdSetup();
	PortWriteByte(PORT_A, 0xA1);
	dataSetup();
	PortWriteByte(PORT_A, 0xA0);
	dataSetup();
	if(password.size() != 0)
		password.pop_back();
}

void LCDDispThirdRow(byte data, byte currentLoc, bool flag){
	//数字编码
    byte table[10][2] = {
        0xA3, 0xB0,
        0xA3, 0xB1,
        0xA3, 0xB2,
		0xA3, 0xB3,
		0xA3, 0xB4,
		0xA3, 0xB5,
		0xA3, 0xB6,
		0xA3, 0xB7,
		0xA3, 0xB8,
		0xA3, 0xB9,
    };
	//键盘与数字的映射
	byte key_val_map[10] = {0x77, 0x7B, 0x7D, 0x7E, 0xB7, 0xBB, 0xBD, 0xBE, 0xD7, 0xDB};
	//要显示的数字
	int num = -1;
	for(int i = 0; i < 10; i++){
		if(key_val_map[i] == data)
			num = i;
	}

	//添加记录
	if(flag){
		if(password.size() == 6)
			password.pop_back();
		password.push_back(num);
	}

	//指定位置显示指定数字
	printf("In fun:%d\n", currentLoc);
	PortWriteByte(PORT_A, currentLoc);
	cmdSetup();
	//PortWriteByte(PORT_A, table[num][0]);
	PortWriteByte(PORT_A, 0xA3);
	dataSetup();
	//PortWriteByte(PORT_A, table[num][1]);
	PortWriteByte(PORT_A, 0xAA);
	dataSetup();
}

byte reWritePassword(){
	byte currentLoc = 0x89;
	while(currentLoc <= 0x8E){
		PortWriteByte(PORT_A, currentLoc);
		cmdSetup();
		PortWriteByte(PORT_A, 0xA1);
		dataSetup();
		PortWriteByte(PORT_A, 0xA0);
		dataSetup();
		currentLoc++;
	}
	password.clear();
	return currentLoc - 1;
}

void LCDDispSuccess(){
	//汉字编码
    byte table[16][2] = {
        0xCC, 0xE1,
        0xCA, 0xBE,
        0xA3, 0xBA,
        0xA1, 0xA0,
        0xA1, 0xA0,
		0xA1, 0xA0,
		0xA1, 0xA0,
        0xA1, 0xA0,

		0xA1, 0xA0,
		0xC3, 0xDC,
        0xC2, 0xEB,
		0xD5, 0xFD,
		0xC8, 0xB7,
		0xA3, 0xA1,
		0xA1, 0xA0,
		0xA1, 0xA0
    };

    //第二行基地址
    byte baseAddr = 0x90;

    //显示
    for (int i = 0; i < 16; i++) {

        //调用CMDSetup，设定DDRAM的地址
        PortWriteByte(PORT_A, baseAddr);       //0x90是第一行首地址
        cmdSetup();
        baseAddr = baseAddr + 1;
        //送高字节
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //送低字节
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
		
		//换行
		if(baseAddr == 0x98)
			baseAddr = 0x88;
    }
}

void LCDDispDeafuat(){
	//汉字编码
    byte table[16][2] = {
        0xCC, 0xE1,
        0xCA, 0xBE,
        0xA3, 0xBA,
        0xA1, 0xA0,
        0xA1, 0xA0,
		0xA1, 0xA0,
		0xA1, 0xA0,
        0xA1, 0xA0,

		0xA1, 0xA0,
		0xC3, 0xDC,
        0xC2, 0xEB,
		0xB4, 0xED,
		0xCE, 0xF3,
		0xA3, 0xA1,
		0xA1, 0xA0,
		0xA1, 0xA0
    };

    //第二行基地址
    byte baseAddr = 0x90;

    //显示
    for (int i = 0; i < 16; i++) {

        //调用CMDSetup，设定DDRAM的地址
        PortWriteByte(PORT_A, baseAddr);       //0x90是第一行首地址
        cmdSetup();
        baseAddr = baseAddr + 1;
        //送高字节
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //送低字节
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
		
		//换行
		if(baseAddr == 0x98)
			baseAddr = 0x88;
    }
}

void LCDDispSetting(){
	//汉字编码
    byte table[16][2] = {
        0xCC, 0xE1,
        0xCA, 0xBE,
        0xA3, 0xBA,
        0xA1, 0xA0,
        0xA1, 0xA0,
		0xA1, 0xA0,
		0xA1, 0xA0,
        0xA1, 0xA0,

		0xA1, 0xA0,
		0xC9, 0xE8,
        0xD6, 0xC3,
		0xB3, 0xC9,
		0xB9, 0xA6,
		0xA3, 0xA1,
		0xA1, 0xA0,
		0xA1, 0xA0
    };

    //第二行基地址
    byte baseAddr = 0x90;

    //显示
    for (int i = 0; i < 16; i++) {

        //调用CMDSetup，设定DDRAM的地址
        PortWriteByte(PORT_A, baseAddr);       //0x90是第一行首地址
        cmdSetup();
        baseAddr = baseAddr + 1;
        //送高字节
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //送低字节
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
		
		//换行
		if(baseAddr == 0x98)
			baseAddr = 0x88;
    }
}

/*=================键盘部分========================*/
byte keyBoard()
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
			return encode();
		}
	}
	return 0x00;
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

/*=================密码部分========================*/
void readPassword(){
	PASSWORD.clear();
	FILE* fp = fopen("code.txt", "r");
	if(fp == NULL){
		printf("open error\n");
		return;
	}
	char ch;
	while((ch = fgetc(fp)) != EOF){
		PASSWORD.push_back(Ret(ch - '0'));
	}
	fclose(fp);
	printf("读取密码成功!\n");
}

bool passwordRight(){
	printf("当前密码：");
	for(int j=0; j<password.size();j++)
		cout<<password[j]<<" ";
	printf("\n");
	if(password.size() != 6)
		return false;
	//判断海关密码
	bool flag = true;
	for(int k = 0; k < customsCode.size(); k++){
		if(password[k] != customsCode[k])
			flag = false;
	}
	if(flag)
		return true;

	//判断普通密码
	for(int i = 0; i < password.size(); i++){
		if(password[i] != PASSWORD[i])
			return false;
	}
	return true;
}

void setCustomsCode(){
	customsCode.push_back(0);
	customsCode.push_back(1);
	customsCode.push_back(1);
	customsCode.push_back(0);
	customsCode.push_back(1);
	customsCode.push_back(6);
}
void savePassword(){
	FILE* fp = fopen("code.txt", "w");
	if(fp == NULL){
		printf("open error\n");
		return;
	}
	for(int i = 0; i < 6; i++)
		fputc(Go(password[i]) + '0', fp);
	fclose(fp);
	printf("密码保存成功！\n");
}

int Go(int num){
	return num % 2 == 0 ? num + 1 : num - 1;
}

int Ret(int num){
	return num % 2 == 0 ? num + 1 : num - 1;
}
/*=================继电器部分========================*/
void deviceStart(){
	if(!PortWriteByte(PORT_273, 0x04)){		//00000100
		printf("继电器启动失败\n");
	}
	else
		printf("继电器启动成功\n");
}
/*=================声光报警部分========================*/
void light_sound_warning(){
	if(!PortWriteByte(PORT_273, 0x03)){		//00010000
		printf("声光报警启动失败\n");
	}
	else
		printf("声光报警启动！\n");
	warning--;
	if(warning == 0){
		LCDWarning();
		warning = 1;
	}
	else
		LCDDispDeafuat();
	Sleep(2000);
	PortWriteByte(PORT_273, 0x00);
	for(int i = 0; i < 16; i++){
		LCDDelete(0x90 + i);
	}
	LCDDelete(0x88);
}

//测试
void dispCurrentPassword(){
	printf("当前密码：");
	for(int i = 0; i < password.size(); i++)
		printf("%d ", password[i]);
	printf("\n");
}


/*=================娴嬭瘯閮ㄥ垎==========================*/
void LCDWarning(){
    LCDDispFirstRow();
	LCDDelete(0x92);
	LCDDelete(0x93);
	LCDDelete(0x94);
	LCDDelete(0x95);

	//调用CMDSetup，设定DDRAM的地址
    PortWriteByte(PORT_A, 0x90);       //0x90是第一行首地址
    cmdSetup();
    //送高字节
    PortWriteByte(PORT_A, 0xBE);
    dataSetup();
    Sleep(20);
    //送低字节
    PortWriteByte(PORT_A, 0xAF);
    dataSetup();
    Sleep(20);
	//调用CMDSetup，设定DDRAM的地址
    PortWriteByte(PORT_A, 0x91);       //0x90是第一行首地址
    cmdSetup();
    //送高字节
    PortWriteByte(PORT_A, 0xB8);
    dataSetup();
    Sleep(20);
    //送低字节
    PortWriteByte(PORT_A, 0xE6);
    dataSetup();
    Sleep(20);
    //警告
    //密码错误过多！
    //密码锁已被锁定！
    byte table[16][2] = {
        0xB4, 0xED,
        0xCE, 0xF3,
        0xB4, 0xCE,
        0xCA, 0xFD,
        0xB9, 0xFD,
        0xB6, 0xE0,
        0xA3, 0xA1,
        0xA1, 0xA0,

        0xC3, 0xDC,
        0xC2, 0xEB,
        0xCB, 0xF8,
        0xD2, 0xD1,
        0xB1, 0xBB,
        0xCB, 0xF8,
        0xB6, 0xA8,
        0xA3, 0xA1,
    };
    byte baseAddr = 0x88;
    for (int i = 0; i < 16; i++) {
        PortWriteByte(PORT_A, baseAddr);       
        cmdSetup();
        baseAddr = baseAddr + 1;
        if(baseAddr == 0x90) baseAddr = 0x98;
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
    }
}