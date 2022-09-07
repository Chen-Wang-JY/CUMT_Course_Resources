/*题目描述
一个字符串A的子串被定义成从A中顺次选出若干个字符构成的串。如A=“cdaad" ,顺次选1，3，5个字符就构成子串" cad" ,现给定两个字符串，求它们的最长共公子串。
输入
第一行两个字符串用空格分开。两个串的长度均小于2000 。
输出
最长子串的长度。

样例输入 Copy
abccd aecd
样例输出 Copy
3
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string a, b;

int main()
{
	cin>>a>>b;
	int lengthA = a.size();
	int lengthB = b.size();
	vector<vector<int>> dp(lengthA + 1, vector<int>(lengthB + 1, 0));
	vector<vector<int>> tb(lengthA + 1, vector<int>(lengthB + 1, 0));
	for(int i = 1; i <= lengthA; i++){
		for(int j = 1; j <= lengthB; j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				tb[i][j] = 1;
			}
			else if(dp[i - 1][j] >= dp[i][j - 1]){
				dp[i][j] = dp[i - 1][j];
				tb[i][j] = 2;
			}
			else{
				dp[i][j] = dp[i][j - 1];
				tb[i][j] = 3;
			}
		}
	}
	cout<<dp[lengthA][lengthB]<<endl;
	return 0;
}
