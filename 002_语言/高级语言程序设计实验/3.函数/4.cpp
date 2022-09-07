#include<iostream>
#include<cmath>
using namespace std;
bool symm(long n) {
	long N = 0;
	long n1 = n;
	while (n) {
		N = N * 10 + n % 10;
		n = n / 10;
	}
	return N == n1;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
		if (symm(i) && symm(7 * i) && symm(3 * i * i))
			cout << i << " ";
	return 0;
}