/*题目描述
一个特别的单行街道在每公里处有一个汽车站。顾客根据他们乘坐汽车的公里使来付费。例如下表就是一个费用的单子。没有一辆车子行驶超过10公里，一个顾客打算行驶n公里(1<=n<100)，它可以通过无限次的换车来完成旅程。最后要求费用最少。
输入
第一行十个整数分别表示行走1到10公里的费用(<=500)。注意这些数并无实际的经济意义，即行驶10公里费用可能比行驶一公里少。第二行一个整数n表示，旅客的总路程数。
输出
仅一个整数表示最少费用。

样例输入 Copy
12 21 31 40 49 58 69 79 90 101
15
样例输出 Copy
147
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cost[11];
    for(int i = 1; i <= 10; i++)
        cin >> cost[i];
    int n;
    cin >> n;
    int dp[110];
    for(int i = 1; i <= n; i++)
        dp[i] = cost[i];
    for(int i = 2; i <= n; i++){
        dp[i] = i > 10 ? int(pow(2, 16)) : dp[i];
        for(int j = 1; j < i; j++){
            int temp = dp[j] + dp[i - j];
            if(temp < dp[i])
                dp[i] = temp;
        }
    }
    cout<<dp[n]<<endl;
    return 0; 
}