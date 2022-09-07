/*题目描述
农历新年马上就要到了，奶牛们计划举办一次聚会庆祝新年的到来。但是，奶牛们并不喜欢走太远的路，这会给他们的聚会带来消极情绪，当一头奶牛的消极指数为Wi，他参加聚会所需行走的距离为si，那么他就会给聚会带来Si3*Wi的消极情绪。所有奶牛所在位置都在一条直线上，已知所有奶牛的坐标和消极指数，求如何确定聚会地点，使得所有奶牛给聚会带来的消极情绪之和最小，输出消极情绪之和的最小值。

输入
第一行包含一个整数 Ca(Ca<=20) ，表示有 Ca 组测试数据。
对于每组测试数据：第一行包含一个整数n(1<=n<=50000) ，表示奶牛的数量。接下来 n 行每行包含两个浮点数Si和wi (-106<=Si<=106, 0<Wi<15)。

输出
对于每组测试数据，输出 "Case #c: ans" ，其中c表示测试数据编号，ans表示消极情绪之和的最小值，结果四舍五入为一个整数。
样例输入 Copy
1
5
0.9 2
1.4 4
3.1 1
6.2 1
8.3 2
样例输出 Copy
Case #1: 300
*/
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

double s[50010];
double w[50010];
int n;

double fun(double x){
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += pow(abs(s[i] - x), 3) * w[i];
    return sum;
}

int main() {
    int Ca;
    cin >> Ca;
    for(int count = 1; count <= Ca; count++){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> s[i];
            cin >> w[i];
        }
        //三分
        double midl, midr;
        double left =  -pow(10, 6) - 1;
        double right = pow(10, 6) + 1;
        while(right - left >= 1e-8){
            midl = (left + right) / 2;
            midr = (midl + right) / 2;
            if(fun(midl) < fun(midr))
                right = midr;
            else
                left = midl;
        }
        //cout<<round(fun(left))<<endl;
        printf("Case #%d: %.0f\n", count, round(fun(left)));
    }
    return 0;
}
