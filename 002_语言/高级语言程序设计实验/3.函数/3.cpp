#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> a;
int Sum(int x) {
	int sum = 1;
	for(int i=2;i<=sqrt(x);i++)
		if (x % i == 0) {
			sum += i;
			sum += x / i;
		}
	return sum;
}
int main()
{
	int start, end;
	cin >> start >> end;
	int r = 1;
	for (int i = start; i <= end; i++) {
		if (Sum(i) > Sum(r))
			r = i;
	}
	cout << r << " " << Sum(r);
	return 0;
}