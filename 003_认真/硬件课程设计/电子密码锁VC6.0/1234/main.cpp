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
		std::cout << "������" << std::endl;
		return;
		
	}
	if (!PortWriteByte(PORT_A, data)) {
		std::cout << "д����" << std::endl;
		return;
	}
}

void keyBoard()
{
	byte data;	//�Ĵ���

	//����������0
	PortWriteByte(PORT_C, 0x00);
	//���У��鿴���м��Ƿ��ɿ�
	while (1) {
		if (!PortReadByte(PORT_B, &data)) {
			printf("QQQQ");
		}
		//��ȡ�ĸ����ߣ�ȫΪ�ߵ�λ�����м��ɿ���
		data = data & 0x0f;
		if (data != 0x0f)		//�м����������ѭ��
			continue;
		//�ж��Ƿ��м�����
		while (1) {

			if (!PortReadByte(PORT_B, &data)) {
				printf("�����ݴ���\n");
			}
			data = data & 0x0f;
			if (data != 0x0f)
				break;
		}
		//�м����£��ӳ�20ms����������
		Sleep(20);
		//�ٲ��У��Ƿ����м�����
		if (!PortReadByte(PORT_B, &data)) {
			printf("�ڶ��δ���\n");
		}
		data = data & 0x0f;
		if (data == 0x0f)		//�޼����������¶���
			continue;
		else {
			break;				//�м��������˳���ѭ��
		}
	}
	//���м����£�ȷ����λ
	byte location = 0xFE;
	while (1) {

		//ʹһ�б�Ϊ�͵�ƽ
		PortWriteByte(PORT_C, location);
		//�������״̬
		PortReadByte(PORT_B, &data);
		//ֻ��ȡ��ֵ
		data = data & 0x0F;
		//�Ƿ��Ϊ1��
		if (data == 0x0F) {
			//��Ϊ1�����Ǹ��а�������
			location = location << 1;			//���ƣ��ж���һ��
			location = location + 1;
			continue;
		}
		else {
			//����Ϊ1�����а���������
			//while(1) printf("���룡����\n"); 
			encode();
			break;
		}
	}
}

//���̱��뺯��01110111
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