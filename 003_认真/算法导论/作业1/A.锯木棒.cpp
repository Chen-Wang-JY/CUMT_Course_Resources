/*题目描述
xiaok大佬最近再雇佣工人给他掰木棒。把一根长为L的木棒锯成两段，他需要支付给工人L元钱。xiaok大佬一开始只有长为L的一根木棒，他想把它锯成n段，每段长度分别为L1,L2,...,Ln，问xiaok大佬最少要付给工人多少钱？
输入
第一行两个整数n,L(1<n<103,n<L<109)
第二行n个整数L1,L2,...,Ln（0<Li<L,且保证L1+L2+...+Ln=L）
输出
输出一个整数，表示最小花费
样例输入 Copy
3 21
8 5 8
样例输出 Copy
34
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long n, L;

int main()
{
	cin>>n>>L;
	priority_queue<long,vector<long>,greater<long>> q;
	for(int i = 0; i < n; i++)
	{
		long x;
		cin>>x;
		q.push(x);
	}
	long cost = 0;
	while(q.size() > 1){
		long x = q.top();
		q.pop();
		long y = q.top();
		q.pop();
		cost += (x + y);
		q.push(x + y);
	}
	cout<<cost<<endl;
	return 0;
}