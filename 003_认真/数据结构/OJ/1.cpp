#include<iostream>
#include<stack>
using namespace std;
bool IsPalindrom(string x) {
	for (int i = 0; i < x.length() / 2; i++)
		if (x[i] != x[x.length() - i - 1])
			return false;
	return true;
}
string Change(int x, int R) {
	stack<int> s;
	string ans = "";
	while (x) {
		s.push(x % R);
		x = x / R;
	}
	while (!s.empty()) {
		int y = s.top();
		if (y >= 0 && y <= 9)
			ans = ans + char(y + '0');
		else
			ans = ans + char(y - 10 + 'A');
		s.pop();
	}
	return ans;
}

int main()
{
	int x;
	cin >> x;
	while (x != 0) {
		int a[17] = { 0 };
		bool flag = false;
		for (int i = 2; i <= 16; i++) {
			string s = Change(x, i);
			if (IsPalindrom(s)) {
				a[i] = 1;
				flag = true;
			}
		}
		if (flag) {
			cout << "Number " << x << " is palindrom in basis";
			for (int i = 2; i <= 16; i++) {
				if (a[i] == 1)
					cout << " " << i;
			}
			cout << endl;
		}
		else
			cout << "Number " << x << " is not a palindrom";
		cin >> x;
	}
	return 0;
}