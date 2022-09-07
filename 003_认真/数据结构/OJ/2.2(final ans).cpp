#include<iostream>
#include<vector>
using namespace std;
int min(int a, int b, int c, int d) {
	if (a > b)
		a = b;
	if (a > c)
		a = c;
	if (a > d)
		a = d;
	return a;
}
bool IsHumble(int x) {
	while (x % 2 == 0)
		x = x / 2;
	while (x % 3 == 0)
		x = x / 3;
	while (x % 5 == 0)
		x = x / 5;
	while (x % 7 == 0)
		x = x / 7;
	return x == 1;
}
void print(int x) {
	if (x%100>10&&x%100<20) {
		cout << "The " << x << "th humble number is ";
		return;
	}
	else if (x%10==1) {
		cout << "The " << x << "st humble number is ";
		return;
	}
	else if (x%10==2) {
		cout << "The " << x << "nd humble number is ";
		return;
	}
	else if (x%10==3) {
		cout << "The " << x << "rd humble number is ";
		return;
	}
	else {
		cout << "The " << x << "th humble number is ";
		return;
	}
}
int main()
{
	long long V[6000];
	V[1] = 1;
	int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
	for (int i = 2; i <= 5843; i++) {
		V[i] = min(V[p2] * 2, V[p3] * 3, V[p5] * 5, V[p7] * 7);
		if (V[i] == V[p2] * 2)p2++;
		if (V[i] == V[p3] * 3)p3++;
		if (V[i] == V[p5] * 5)p5++;
		if (V[i] == V[p7] * 7)p7++;
	}
	int x;
	cin >> x;
	while (x != 0) {
		print(x);
		cout << V[x] << "." << endl;
		cin >> x;
	}
	return 0;
}