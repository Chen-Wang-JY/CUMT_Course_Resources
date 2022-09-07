#include<iostream>
#include<vector>
using namespace std;
bool IsHumble(int x) {
	while (x % 2 == 0)
		x = x / 2;
	while (x % 3 == 0)
		x = x / 3;
	while (x % 5 == 0)
		x = x / 5;
	while (x % 7 == 0)
		x = x / 7;
	return x==1;
}
int Humble(int x) {
	vector<int> V(x+1,0);
	V[1] = 1;
	int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
	for (int i = 2; i <= x; i++) {
		V[i] = min(V[p2] * 2, V[p3] * 3);
		V[i] = min(V[i], V[p5] * 5);
		V[i] = min(V[i], V[p7] * 7);
		if (V[i] == V[p2] * 2)p2++;
		if (V[i] == V[p3] * 3)p3++;
		if (V[i] == V[p5] * 5)p5++;
		if (V[i] == V[p7] * 7)p7++;
	}
	return V[x];
}
void print(int x) {
	if (x == 11 || x == 12 || x == 13) {
		cout << "The " << x << "th humble number is ";
		return;
	}
	else if ((x - 1) % 10 == 0) {
		cout << "The " << x << "st humble number is ";
		return;
	}
	else if ((x - 2) % 10 == 0) {
		cout << "The " << x << "nd humble number is ";
		return;
	}
	else if ((x - 3) % 10 == 0) {
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
	int x;
	cin >> x;
	while (x != 0) {
		print(x);
		cout << Humble(x) << "." << endl;
		cin >> x;
	}
	return 0;
}