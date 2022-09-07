#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long N;
	cin >> N;
	//int length = 0;
	//long n = N;
	//while (n) {
	//	n = n / 16;
	//	length++;
	//}
	vector<char>V;
	while (N) {
		int r = N % 16;

		if (r <= 9)
			V.push_back('0' + r);
		else
			V.push_back('A' + r-10);
		N = N / 16;
	}
	for (int i = V.size(); i > 0; i--)
		cout << V[i-1];
	return 0;
}