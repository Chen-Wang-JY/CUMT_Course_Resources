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
#define PATHINF 500

using namespace std;

int main()
{
    int n, m, start, End;
    int scores[610];
    int paths[610][610];
    int dist[610];
    bool s[610];
    
    cin >> n >> m >> start >> End;
    for(int i = 0; i < n; i++){
        cin>>scores[i];
        s[i] = false;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j)
                paths[i][j] == 0;
            else
                paths[i][j] = PATHINF;

    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        paths[x][y] = z;
        paths[y][x] = z;
    }

    int ansScores[610];
    for(int i = 0; i < n; i++){
        dist[i] = paths[start][i];
        ansScores[i] = scores[start] + scores[i];
        s[i] = false;
    }
    s[start] = true;
    ansScores[start] = scores[start];
    
    for(int i = 0; i < n - 1; i++){
        int min = PATHINF;
        int u = start;
        for(int j = 0; j < n; j++)
            if(!s[j] && dist[j] < min){
                u = j;
                min = dist[j];
            }
        s[u] = true;
        for(int j = 0; j < n; j++){
            if(!s[j] && paths[u][j] < PATHINF && dist[u] + paths[u][j] < dist[j]){
                dist[j] = paths[u][j] + dist[u];
                s[j] = true;
                ansScores[j] = scores[j] + ansScores[u];
            }
            else if(!s[j] && paths[u][j] < PATHINF && dist[u] + paths[u][j] == dist[j]){
                ansScores[j] = max(ansScores[j], scores[j] + ansScores[u]);
                s[j] = true;
            }
        }
    }
    cout<<dist[End]<<" "<<ansScores[End]<<endl;
    

    return 0;
}


