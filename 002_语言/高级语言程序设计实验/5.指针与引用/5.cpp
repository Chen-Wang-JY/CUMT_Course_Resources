//#include<iostream>
//using namespace std;
//int length(unsigned long x) {
//	int count = 0;
//	while (x) {
//		count++;
//		x = x / 10;
//	}
//	return count;
//}
//int f(unsigned long x, int n, int& Lxn) {
//	int Rxn=0,i=1;
//	while (x) {
//		int r = x % 10;
//		if (i == n)
//			Rxn = r;
//		if (i == (length(x) - n + 1))
//			Lxn = r;
//		x = x / 10;
//		i++;
//	}
//	return Rxn;
//}
//int main()
//{
//	unsigned long x;
//	int n;
//	cin >> x >> n;
//	int Lxn=0;
//	int Rxn = f(x, n, Lxn);
//	cout << Rxn << " " << Lxn;
//	return 0;
//}

#include<iostream>
using namespace std;
int f(unsigned long x, int n, int& Lxn) {
	int count = 0;
	int z = x;
	while (z) {
		z = z / 10;
		count++;
	}
	if (count < n||n==0) {
		Lxn = 0;
		return 0;
	}
	int y = 0, i = 1;
	while (x) {
		int r = x % 10;
		if (i == (count - n+1 ))
			Lxn = r;
		if (i == n)
			y = r;
		x = x / 10;
		i++;
	}
	return y;
}
int main()
{
	unsigned long x;
	int n;
	cin >> x >> n;
	int Lxn;
	int Rxn = f(x, n, Lxn);
	cout << Rxn << " " << Lxn << endl;
	return 0;
}