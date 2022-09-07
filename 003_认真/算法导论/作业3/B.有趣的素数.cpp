#include <iostream>
#include <cstring>
using namespace std;
int n;
// int isPrime[35] = {
//     0,1,1,1,0,1,0,1,0,0,0,
//     1,0,1,0,0,0,1,0,1,0,
//     0,0,1,0,0,0,0,0,1,0,
//     1,0,0,0
// };
bool isPrime[40]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
int ans;
bool visited[17] = {false};
int count;
int first;
int last;
void DFS(int num){
    if(count == n){
        if(isPrime[first + num])
            ans++;
        else
            return;
    }
    for(int i = 1; i <= n; i++){
        if(visited[i])
            continue;
        if(!isPrime[i + last])
            continue;

        visited[i] = true;
        count++;
        int temp = last;
        last = i;
        DFS(i);
        last = temp;
        count--;
        visited[i] = false;
    }
}

int main()
{
    ans = 0;
    count = 1;
    while(cin >> n){
        memset(visited, 0, sizeof(visited));
        ans = 0;
        visited[1] = true;
        first = 1;
        last = 1;
        DFS(1);
        visited[1] = false;
        cout << ans << endl;
    }
    return 0;
}