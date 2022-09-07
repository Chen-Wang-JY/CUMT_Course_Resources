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
#include <algorithm>
using namespace std;

typedef long long ll;

struct worker
{
    ll startTime;
    ll endTime;

    bool operator < (worker& w){
        if(this->startTime == w.startTime)
            return this->endTime < w.endTime;
        return this->startTime < w.startTime;
    }
};


int main()
{
    int N;
    cin >> N;
    worker workers[5010];
    ll startTime[5010];
    ll endTime[5010];
    for(int i = 0; i < N; i++){
        cin >> workers[i].startTime >> workers[i].endTime;
    }
    sort(workers, workers + N);
    ll workingTime = 0;
    ll ans1 = workers[0].endTime - workers[0].startTime;
    ll st1 = workers[0].startTime;
    ll et1 = workers[0].endTime;
    ll ans2 = 0;
    for(int i = 1; i < N; i++){
        if(workers[i].startTime > et1){
            ans2 = max(ans2, workers[i].startTime - et1);
            st1 = workers[i].startTime;
        }
        et1 = max(et1, workers[i].endTime);
        ans1 = max(ans1, et1 - st1);
        // if(workers[i].startTime > workers[i - 1].endTime){
        //     if(ans1 < workers[i - 1].endTime - st1)
        //         ans1 = workers[i - 1].endTime - st1;
        //     st1 = workers[i].startTime;
        // }
    }
    
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}