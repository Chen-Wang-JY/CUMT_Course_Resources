/*题目描述
给定n(1<=n<=1000000)个元素，求第k小数(1<=k<=n)。

输入
一组样例。第一行输入两个整数n和k。第二行输入n个不同的int范围内的数。

输出
输出一行，输出第k小数。

样例输入 Copy
5 2
1 5 3 2 4

样例输出 Copy
2
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string ans = "";
	while(n){
		int r = n % 8;
		ans.push_back(r + '0');
		n = n / 8;
	}
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;
}