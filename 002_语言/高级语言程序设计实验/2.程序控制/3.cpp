#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 6; i <= n; i = i + 10)
		if (i % 3 == 1)
			cout << i << " ";
	return 0;
}