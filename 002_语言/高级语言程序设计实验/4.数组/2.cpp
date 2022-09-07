#include <iostream>
using namespace std;
bool End(int* p) {
	int count = 0;
	for (int i = 0; i < 12; i++)
		if (p[i] == 1)
			count++;
	if (count == 11)
		return true;
	return false;
}
int main()
{
	int k;
	cin >> k;
	int a[12] = { 0 };
	int index=0;//报数人的下标
	while (!End(a)) {
		int r = 0;
		for (int i = index; ; i++) {
			if (i >= 12)
				i = 0;
			if (a[i] == 0)
				r++;
			if (r == k) {
				a[i] = 1;
				index = i + 1;
				break;
			}
		}
	}
	for (int i = 0; i < 12; i++)
		if (a[i] == 0) {
			cout << i + 1;
			break;
		}
	return 0;
}

