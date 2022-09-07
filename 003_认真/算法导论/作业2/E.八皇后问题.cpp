/*题目描述
努比亚和苏丹没有子女，所以他要从一些有集成资格的继承者中挑选一个出来继承王位。他希望这个继承者足够聪明，所以他准备了一个西洋棋盘，上面的每个格子中均有一个 1-99 的数字。他又准备了 8 个皇后棋子。
8 皇后的规则就是不能有任何棋子同行或者同列或者同斜线，在满足这个规则的同时，王位继承者还需要让 8 个皇后所在的位置的数字的和是最大的。
输入
输入一个数字 k(k≤20)，代表棋盘的数量。
接下来有 k 个棋盘，每个棋盘有 64 个数字，分成 8 行 8 列输入，具体可见样例，每一个数字均小于 100。
输出
        每一个棋盘对应输出最大的数值， 一共输出 k行
样例输入 Copy
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64
样例输出 Copy
260
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int desktop[8][8];
int row[8];
int maxAns = -1;

void traceback(int currentRow){
	if(currentRow == 8){
		int temp = 0;
		for(int i = 0; i < 8; i++){
			temp += desktop[i][row[i]];
		}
		maxAns = max(maxAns, temp);
	}
	else{
		//在currentRow行，寻找可以落子的列
		for(int j = 0; j < 8; j++){
			bool flag = true;
			row[currentRow] = j;
			for(int i = 0; i < currentRow; i++){
				//之前那些行，某一个棋子的位置 i, row[i]
				//当前试图落子的位置		  currentRow, j
				int x = currentRow - i;
				int y = j - row[i];
				if(row[i] != -1 && (row[i] == j || abs(x) == abs(y)))
				{
					flag = false;
					break;
				}
			}
			if(flag)
				traceback(currentRow + 1);
			row[currentRow] = -1;
		}
	}
}

int main()
{
	int k;
	cin >> k;
	while(k--){
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				cin >> desktop[i][j];
		for(int i = 0; i < 8; i++){
			row[i] = -1;
		}
		traceback(0);
		cout<<maxAns<<endl;
	}
}

