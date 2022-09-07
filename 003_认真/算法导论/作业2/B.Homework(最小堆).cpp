/*题目描述
你来到一个迷宫前。该迷宫由若干个房间组成，每个房间都有一个得分，第一次进入这个房间，你就可以得到这个分数。还有若干双向道路连结这些房间，你沿着这些道路从一个房间走到另外一个房间需要一些时间。游戏规定了你的起点和终点房间，你首要目标是从起点尽快到达终点，在满足首要目标的前提下，使得你的得分总和尽可能大。现在问题来了，给定房间、道路、分数、起点和终点等全部信息，你能计算在尽快离开迷宫的前提下，你的最大得分是多少么？
输入
第一行4个整数n (<=500), m, start, end。n表示房间的个数，房间编号从0到(n - 1)，m表示道路数,任意两个房间之间最多只有一条道路，start和end表示起点和终点房间的编号。
第二行包含n个空格分隔的正整数(不超过600)，表示进入每个房间你的得分。
再接下来m行，每行3个空格分隔的整数x, y, z (0<z<=200)表示道路,表示从房间x到房间y(双向)的道路,注意，最多只有一条道路连结两个房间,你需要的时间为z。
输入保证从start到end至少有一条路径。
输出
 占一行，分别最短时间和相应的最大得分，中间用空格隔开。
样例输入 Copy
3 2 0 2
1 2 3
0 1 10
1 2 11
样例输出 Copy
21 6
*/
#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;

int M, N;

struct homework
{
    int time;
    int value;
    
    bool operator<(const homework& a) const{
        if(this->time == 0)
            return true;
        else if(a.time == 0)
            return false;
        return (this->value / this->time) < (a.value / a.time);
    }
};

int main()
{
    priority_queue<homework> Q;
    homework work;
    while(cin>>M>>N && (M != 0 || N != 0)){
        int T, V;
        for(int i = 0; i < M; i++){
            cin >> work.time >> work.value;
            Q.push(work);
        }
        double ans = 0;
        while(N > 0){
            if(N >= Q.top().time){
                N = N - Q.top().time;
                ans += Q.top().value;
                Q.pop();
            }
            else{
                ans += 1.0 * Q.top().value / Q.top().time * N;
                N = 0;
            }
        }
        cout<<fixed<<setprecision(2);
        cout<<ans<<endl;
    }

    return 0;
}


