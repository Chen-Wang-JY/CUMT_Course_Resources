/*题目描述
给定n个矩阵{A1,A2,...,An}，及m个矩阵连乘的表达式，判断每个矩阵连乘表达式是否满足矩阵乘法法则，
如果满足，则计算矩阵的最小连乘次数，如果不满足输出“MengMengDa“。

输入
输入数据由多组数据组成（不超过10组样例）。每组数据格式如下：
第一行是2个整数n (1≤n≤26)和m(1≤m≤3)，表示矩阵的个数。
接下来n行，每行有一个大写字母，表示矩阵的名字，后面有两个整数r和c，分别表示该矩阵的行数和列数，其中1<r, c<100。
第n+1行到第n+m行，每行是一个矩阵连乘的表达式(2<=矩阵个数<=100)。

输出
对于每个矩阵连乘表达式，如果运算不满足矩阵乘法法则的情况（即左矩阵列数与右矩阵的行数不同），则输出“MengMengDa”，否则输出最小矩阵连乘次数。
数据保证结果不超过1e9。

样例输入 Copy
3 2
A 10 100
B 5 50
C 100 5
ACB
ABC

样例输出 Copy
7500
MengMengDa
*/
#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<char, pair<int, int>> matrix;
string s[11];

int main()
{
	while(cin>>n>>m){
		matrix.clear();
		for(int i = 0; i < n; i++){
			char ch;
			int x, y;
			cin>>ch>>x>>y;
			matrix[ch] = pair<int, int>(x, y);
		}
		for(int i = 0; i < m; i++)
			cin>>s[i];
		
		for(int q = 0; q < m; q++){
			string expression = s[q];
			bool isLegal = true;
			for(int i = 0; i < expression.size() - 1; i++){
				char thisMatrix = expression[i];
				char nextMatrix = expression[i + 1];
				if(matrix[thisMatrix].second != matrix[nextMatrix].first){
					isLegal = false;
					break;
				}
			}
			if(!isLegal){
				cout<<"MengMengDa"<<endl;
				continue;
			}
			int dp[110][110];
			int rank = expression.size();
			for(int i = 1; i <= rank; i++)
				dp[i][i] = 0;
			for(int r = 1; r < rank; r++){
				for(int i = 1; i + r <= rank; i++){
					int j = i + r;
					dp[i][j] = dp[i][i] + dp[i + 1][j] + matrix[expression[i - 1]].first * matrix[expression[i - 1]].second * matrix[expression[j - 1]].second;
					for(int k = i; k <= j - 1; k++){
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[expression[i - 1]].first * matrix[expression[k - 1]].second * matrix[expression[j - 1]].second);
					}
				}
			}
			cout<<dp[1][rank]<<endl;
		}
	}
	return 0;
}