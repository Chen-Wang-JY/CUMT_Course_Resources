#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long N;
	cin >> N;
	int length = 0;
	long n = N;
	while (n) {
		n = n / 16;
		length++;
	}
	char* p = new char[length];
	int i = 0;
	while (N) {
		int r = N % 16;

		if (r <= 9) {
			p[i++] = '0'+r;
			//cout << p[i++] << endl;
		}
		else
			p[i++] = 'A' + r - 10;
		N = N / 16;
	}
	for (int i = length; i > 0; i--)
		cout << p[i-1];
	return 0;
}