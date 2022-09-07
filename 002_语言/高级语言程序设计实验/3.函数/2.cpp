#include<iostream>
#include<cmath>
using namespace std;
bool F(int x) {
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}
void find(int i, int n) {
	for (; n > 0; i++) 
		if (F(i)) {
			cout << i << " ";
			n--;
		}
}
int main()
{
	int i, n;
	cin >> i >> n;
	find(i, n);
	return 0;
}