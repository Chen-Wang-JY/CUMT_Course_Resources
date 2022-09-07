#include<iostream>
#include<cmath>
using namespace std;
int Sum(int x) {
	int sum = 1;
	for (int i = 2; i <=x/2; i++)
		if (x % i == 0) {
			sum += i;
		}
	return sum;
}
int main()
{
	int start, end;
	cin >> start >> end;
	int r = start;
	for (int i = start; i <= end; i++) {
		if (Sum(i) > Sum(r))
			r = i;
	}
	cout << r << " " << Sum(r);
	return 0;
}