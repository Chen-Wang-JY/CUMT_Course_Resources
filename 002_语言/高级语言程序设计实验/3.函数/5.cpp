#include<iostream>
#include<cmath>
using namespace std;
long symm(long n) {
	long N = 0;
	while (n) {
		N = N * 10 + n % 10;
		n = n / 10;
	}
	return N;
}
int main()
{
	int n;
	cin >> n;
	cout << n + symm(n);
	return 0;
}