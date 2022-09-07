#include<iostream>
#include<stack>
using namespace std;
bool IsPrime(int x) {
	if (x == 1)
		return true;
	for (int i = 2; i <= sqrt(x); i++) 
		if (x % i == 0)
			return false;
	return true;
}
bool IsHumble(int x) {
	if (x < 8)
		return true;
	if (IsPrime(x) && x >= 11)
		return false;
	for (int i = 8; i <= x/2; i++) {
		if (IsPrime(i) && x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int x;
	cin >> x;
	while (x != 0) {
		int i = 0;
		int j = 1;
		while (i!=x) {
			if (IsHumble(j))
				i++;
			j++;
		}
		cout << j - 1 << endl;




		cin >> x;
	}
	return 0;
}