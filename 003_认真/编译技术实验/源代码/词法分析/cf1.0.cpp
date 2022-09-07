#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;

char fileName[30];		//文件名
char program[1000];		//待分析程序
char token[8];			//已识别部分，最大长度为8
char ch;
int p = 0;
int sym = 0;
int n;
FILE* fp;				//文件指针
const char* keyWord[8] = { "if", "then", "else", "end", "repeat", "until", "read", "write" };	//关键字集合
void formatPrint(string s);
void getToken();


int main()
{
	p = 0;
	cout << "请输入源文件名：";
	while (true) {
		cin >> fileName;
		fp = fopen(fileName, "r");
		if (fp != 0) break;
		else
			cout << "文件路径错误，请重新输入源文件名：" << endl;
	}
	//读取待分析程序
	formatPrint("开始读取待分析程序");
	ch = fgetc(fp);
	while (ch != EOF) {
		program[p++] = ch;
		ch = fgetc(fp);
	}
	cout << program << endl;
	program[p] = '$';
	formatPrint("程序读取成功！");
	p = 0;
	do {
		getToken();
		switch (sym)
		{
		case -1:
		case -2: break;
		case 99: break;
		default:
			cout << "(" << sym << ", " << token << ")" << endl;
			break;
		}
	} while (ch != '$');

	return 0;
}

void formatPrint(string s) {
	cout << "----------------------------" << s << "----------------------------" << endl;
}

void getToken()
{
	//清空token
	for (n = 0; n < 8; n++)
		token[n] = '\0';

	n = 0;
	//读取program中第一个有效字符
	ch = program[p++];
	while (ch == ' ' || ch == '\n' || ch == '\t')
		ch = program[p++];
	//送入DFA中
	//cout <<"eeee          " << ch <<endl;
	//字母
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		//DFA进入状态1
		sym = 1;
		while (true) {
			token[n++] = ch;
			ch = program[p++];
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
				continue;
			else
				break;
		}
		//若输入的不是保留字，则DFA进入状态2
		sym = 2;
		for (n = 0; n < 8; n++) {
			//输入的是保留字，DFA进入对应状态
			if (strcmp(token, keyWord[n]) == 0) {
				sym = n + 3;
				break;
			}
		}
		//多读取的字符回退
		p--;
	}
	//左大括号
	else if (ch == '{') {
		while (program[p] != '}')
			p++;
		sym = -1;
		p++;
		return;
	}
	//数字
	else if (ch >= '0' && ch <= '9') {
		//DFA进入状态11
		sym = 11;
		while (ch >= '0' && ch <= '9') {
			token[n++] = ch;
			ch = program[p++];
		}
		p--;
		sym = 12;
		return;
	}
	//其他
	else {
		switch (ch)
		{
		case '+': sym = 13; token[0] = ch; break;
		case '-': sym = 14; token[0] = ch; break;
		case '*': sym = 15; token[0] = ch; break;
		case '/': sym = 16; token[0] = ch; break;
		case '=': sym = 17; token[0] = ch; break;
		case '<': sym = 18; token[0] = ch; break;
		case ';': sym = 19; token[0] = ch; break;
		case '$': sym = 99; return;
		default:
			sym = -2;
			cout << "词法分析出错！" << endl;
			break;
		}
	}
}