/*题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
输入
多组测试样例。每组测试样例包含一个整数n。(1<=n<=100)
输出
每组测试样例输出一行，表示青蛙跳上n级台阶的跳法数量.
所得到的结果模1000000007
样例输入 Copy
3
4
样例输出 Copy
3
5
*/
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n;
long dp[110][110];

int main()
{
    while(cin>>n){
        for(int r = 0; r <= n; r++){
            for(int i = 0; i + r <= n; i++){
                int j = i + r;
                if(i == j) dp[i][j] = 0;
                else if(j - i == 1) dp[i][j] = 1;
                else if(j - i == 2) dp[i][j] = 2;
                else dp[i][j] = dp[i][j - 1] % 1000000007 + dp[i][j - 2] % 1000000007;
            }
        }
        cout<<dp[0][n] % 1000000007<<endl;
    }
    return 0;
}
