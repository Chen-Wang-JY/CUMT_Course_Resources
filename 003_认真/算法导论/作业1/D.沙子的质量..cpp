/*
题目描述
设有N堆沙子排成一排，其编号为1，2，3，…，N（N< =300）。每堆沙子有一定的数量，可以用一个整数来描述，现在要将N堆沙子合并成为一堆，每次只能合并相邻的两堆，合并的代价为这两堆沙子的数量之和，合并后与这两堆沙子相邻的沙子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同，如有4堆沙子分别为1 3 5 2我们可以先合并1、2堆，代价为4，得到4 5 2又合并1，2堆，代价为9，得到9 2，再合并得到11，总代价为4+9+11=24，如果第二步是先合并2，3堆，则代价为7，得到4 7，最后一次合并代价为11，总代价为4+7+11=22；问题是：找出一种合理的方法，使总的代价最小。输出最小代价。

输入
第一行一个数N表示沙子的堆数N。 第二行N个数，表示每堆沙子的质量。 a[i]< =1000。
输出
合并的最小代价。

样例输入 Copy
4
1 3 5 2
样例输出 Copy
22
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
int preSum[10010];
int dp[10010][10010];

int main()
{
	cin>>N;
	int x;
	preSum[0] = 0;
	for(int i = 1; i <= N; i++){
		cin>>x;
		preSum[i] = preSum[i - 1] + x;
	}
	for(int i = 1; i <= N; i++)
		dp[i][i] = 0;
	for(int r = 1; r <= N; r++){
		int i = 1;
		while(i + r <= N){
			int j = i + r;

			int min = 2000;
			for(int k = i; k <= j - 1; k++){
				int temp = dp[i][k] + dp[k + 1][j] + preSum[j] - preSum[i - 1];
				if(min > temp) min = temp;
			}
			dp[i][j] = min;
			
			i++;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<dp[1][N]<<endl;
	return 0;
}