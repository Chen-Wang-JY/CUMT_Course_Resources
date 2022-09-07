#include<iostream>
#include<string>
using namespace std;

string power(string s, int n) {
	string ex = s;
	for (int i = 0; i < n-1; i++)
		s += ex;
	return s;
}
int main()
{
	string s;
	cin >> s;
	while (s != ".") {
		string base;
		int i = 0;
		while (true) {
			base += s[i++];
			if (power(base, s.length() / base.length()) == s) {
				cout << s.length() / base.length() << endl;
				break;
			}
		}
		cin >> s;
	}
	return 0;
}
