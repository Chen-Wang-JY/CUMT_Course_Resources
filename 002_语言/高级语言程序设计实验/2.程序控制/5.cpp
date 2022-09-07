#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = a / b; i > 0; i--)
		if (pow(b, i) <= a) {
			cout << i;
			break;
		}
	return 0;
}