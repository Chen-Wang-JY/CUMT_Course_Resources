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

//��ʼʱ��һ������
void test(){
	byte data;
	if(!PortReadByte(PORT_B, &data)){
		while (!kbhit()) printf("�����ݴ���\n");
	}
}
//����
void dispCurrentPassword();

//��ʼ��
void init();
void formatDisp(byte data);

/*=================LCD����========================*/
//��LCDдָ��
void cmdSetup();
//��LCDд����
void dataSetup();
//LCD����
void LCDClear();
//LCD��ʼ���������趨������ָ��ϣ�
void LCDInit();
//��ʾ
void LCDDispFirstRow();
void LCDDispSecondRow();
void LCDDispSecondRow_1();
void LCDDispSuccess();
void LCDDispDeafuat();
void LCDDispSetting();
void LCDWarning();
//���붯̬��ʾ
void LCDDispThirdRow(byte data, byte currentLoc, bool flag=true);
//��д����
byte reWritePassword();
//���ָ��λ������
void LCDDelete(byte currentLoc);
/*=================���̲���========================*/
//���̱��뺯��
byte encode();
//����һ�ΰ���
byte keyBoard();
/*=================���벿��========================*/
void setCustomsCode();
void readPassword();
bool passwordRight();
void savePassword();
int Go(int num)��
int Ret(int num)��
/*=================�̵�������========================*/
void deviceStart();
/*=================���ⱨ������========================*/
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

	byte currentLoc = 0x88;		//0x89H ~ 0x8EH	 6���� +5
	
	readPassword();
	setCustomsCode();

	byte lastNum = 0xDD;
	bool r = false;
	vector<int> temp;
	/*
	��ǰģʽ
	1��������
	2�����趨����
    */
	int state = 1;
	while(!kbhit()){
		byte num = keyBoard();
		//A �˸�
		if(num == 0xDD){
			LCDDelete(currentLoc);
			if(currentLoc != 0x88){
				currentLoc--;
			}
			if(password.size() != 0)
				lastNum = table[password[password.size() - 1]];
		}
		//E ȷ������
		else if(num ==  0xEE){
			//state==1   ����
			if(state == 1){
				bool flag = passwordRight();
				if(flag){
					printf("������ȷ�������ɹ���\n");
					warning = 3;
					deviceStart();
					LCDDispSuccess();
					Sleep(2000);
					LCDDispSecondRow();
					currentLoc = reWritePassword();
				}
				else{
					printf("�������\n");
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
			//state==2  �趨
			else if(state == 2){
				printf("�趨\n");
				
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
						printf("�������벻һ�£�\n");
						reWritePassword();
						currentLoc = 0x88;
						continue;
					}
					dispCurrentPassword();
					savePassword();
					readPassword();
					printf("���óɹ���\n");
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
		//C �л�ģʽ�����趨/��������
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
		//��ʾ����
		else
		{
			if(currentLoc < 0x8E)
				currentLoc++;
			printf("currentLoc:%d\n", currentLoc);
			LCDDispThirdRow(num, currentLoc);
			lastNum = num;
		}
	}

	printf("��������˳�\n");
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



/*=================LCD����========================*/
void cmdSetup() {
    /*
    8255C�˿ڣ�
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
    8255C�˿ڣ�
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
    //����ָ�����1.�����ʾ
    //��ָ��д��LCD���ݿ�
    PortWriteByte(PORT_A, 0x01);       //0000 0001
    cmdSetup();
}

void LCDInit() {
	LCDClear();
    //����ָ�����6.�����趨
    PortWriteByte(PORT_A, 0x30);       //0011 0000
    cmdSetup();
	PortWriteByte(PORT_A, 0x0C);	   //��ʾ�α�ɶ��
	cmdSetup();
}

void LCDDispFirstRow() {

    //��һ�еĺ��ֱ���
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

    //��һ�л���ַ
    byte baseAddr = 0x80;

    //��ʾ��һ��8������
    for (int i = 0; i < 8; i++) {

        //����CMDSetup���趨DDRAM�ĵ�ַ
        PortWriteByte(PORT_A, baseAddr);       //0x90�ǵ�һ���׵�ַ
        cmdSetup();
        baseAddr = baseAddr + 1;
        //�͸��ֽ�
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //�͵��ֽ�
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
    }
}

void LCDDispSecondRow(){

    //�ڶ��еĺ��ֱ���
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

    //�ڶ��л���ַ
    byte baseAddr = 0x90;

    //��ʾ�ڶ���8������
    for (int i = 0; i < 8; i++) {

        //����CMDSetup���趨DDRAM�ĵ�ַ
        PortWriteByte(PORT_A, baseAddr);       //0x90�ǵ�һ���׵�ַ
        cmdSetup();
        baseAddr = baseAddr + 1;
        //�͸��ֽ�
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //�͵��ֽ�
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
    }
}

void LCDDispSecondRow_1(){
	//�ڶ��еĺ��ֱ���
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

    //�ڶ��л���ַ
    byte baseAddr = 0x90;

    //��ʾ�ڶ���8������
    for (int i = 0; i < 8; i++) {

        //����CMDSetup���趨DDRAM�ĵ�ַ
        PortWriteByte(PORT_A, baseAddr);       //0x90�ǵ�һ���׵�ַ
        cmdSetup();
        baseAddr = baseAddr + 1;
        //�͸��ֽ�
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //�͵��ֽ�
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
	//���ֱ���
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
	//���������ֵ�ӳ��
	byte key_val_map[10] = {0x77, 0x7B, 0x7D, 0x7E, 0xB7, 0xBB, 0xBD, 0xBE, 0xD7, 0xDB};
	//Ҫ��ʾ������
	int num = -1;
	for(int i = 0; i < 10; i++){
		if(key_val_map[i] == data)
			num = i;
	}

	//��Ӽ�¼
	if(flag){
		if(password.size() == 6)
			password.pop_back();
		password.push_back(num);
	}

	//ָ��λ����ʾָ������
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
	//���ֱ���
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

    //�ڶ��л���ַ
    byte baseAddr = 0x90;

    //��ʾ
    for (int i = 0; i < 16; i++) {

        //����CMDSetup���趨DDRAM�ĵ�ַ
        PortWriteByte(PORT_A, baseAddr);       //0x90�ǵ�һ���׵�ַ
        cmdSetup();
        baseAddr = baseAddr + 1;
        //�͸��ֽ�
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //�͵��ֽ�
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
		
		//����
		if(baseAddr == 0x98)
			baseAddr = 0x88;
    }
}

void LCDDispDeafuat(){
	//���ֱ���
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

    //�ڶ��л���ַ
    byte baseAddr = 0x90;

    //��ʾ
    for (int i = 0; i < 16; i++) {

        //����CMDSetup���趨DDRAM�ĵ�ַ
        PortWriteByte(PORT_A, baseAddr);       //0x90�ǵ�һ���׵�ַ
        cmdSetup();
        baseAddr = baseAddr + 1;
        //�͸��ֽ�
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //�͵��ֽ�
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
		
		//����
		if(baseAddr == 0x98)
			baseAddr = 0x88;
    }
}

void LCDDispSetting(){
	//���ֱ���
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

    //�ڶ��л���ַ
    byte baseAddr = 0x90;

    //��ʾ
    for (int i = 0; i < 16; i++) {

        //����CMDSetup���趨DDRAM�ĵ�ַ
        PortWriteByte(PORT_A, baseAddr);       //0x90�ǵ�һ���׵�ַ
        cmdSetup();
        baseAddr = baseAddr + 1;
        //�͸��ֽ�
        PortWriteByte(PORT_A, table[i][0]);
        dataSetup();
        Sleep(20);
        //�͵��ֽ�
        PortWriteByte(PORT_A, table[i][1]);
        dataSetup();
        Sleep(20);
		
		//����
		if(baseAddr == 0x98)
			baseAddr = 0x88;
    }
}

/*=================���̲���========================*/
byte keyBoard()
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
			return encode();
		}
	}
	return 0x00;
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

/*=================���벿��========================*/
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
	printf("��ȡ����ɹ�!\n");
}

bool passwordRight(){
	printf("��ǰ���룺");
	for(int j=0; j<password.size();j++)
		cout<<password[j]<<" ";
	printf("\n");
	if(password.size() != 6)
		return false;
	//�жϺ�������
	bool flag = true;
	for(int k = 0; k < customsCode.size(); k++){
		if(password[k] != customsCode[k])
			flag = false;
	}
	if(flag)
		return true;

	//�ж���ͨ����
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
	printf("���뱣��ɹ���\n");
}

int Go(int num){
	return num % 2 == 0 ? num + 1 : num - 1;
}

int Ret(int num){
	return num % 2 == 0 ? num + 1 : num - 1;
}
/*=================�̵�������========================*/
void deviceStart(){
	if(!PortWriteByte(PORT_273, 0x04)){		//00000100
		printf("�̵�������ʧ��\n");
	}
	else
		printf("�̵��������ɹ�\n");
}
/*=================���ⱨ������========================*/
void light_sound_warning(){
	if(!PortWriteByte(PORT_273, 0x03)){		//00010000
		printf("���ⱨ������ʧ��\n");
	}
	else
		printf("���ⱨ��������\n");
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

//����
void dispCurrentPassword(){
	printf("��ǰ���룺");
	for(int i = 0; i < password.size(); i++)
		printf("%d ", password[i]);
	printf("\n");
}


/*=================测试部分==========================*/
void LCDWarning(){
    LCDDispFirstRow();
	LCDDelete(0x92);
	LCDDelete(0x93);
	LCDDelete(0x94);
	LCDDelete(0x95);

	//����CMDSetup���趨DDRAM�ĵ�ַ
    PortWriteByte(PORT_A, 0x90);       //0x90�ǵ�һ���׵�ַ
    cmdSetup();
    //�͸��ֽ�
    PortWriteByte(PORT_A, 0xBE);
    dataSetup();
    Sleep(20);
    //�͵��ֽ�
    PortWriteByte(PORT_A, 0xAF);
    dataSetup();
    Sleep(20);
	//����CMDSetup���趨DDRAM�ĵ�ַ
    PortWriteByte(PORT_A, 0x91);       //0x90�ǵ�һ���׵�ַ
    cmdSetup();
    //�͸��ֽ�
    PortWriteByte(PORT_A, 0xB8);
    dataSetup();
    Sleep(20);
    //�͵��ֽ�
    PortWriteByte(PORT_A, 0xE6);
    dataSetup();
    Sleep(20);
    //����
    //���������࣡
    //�������ѱ�������
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