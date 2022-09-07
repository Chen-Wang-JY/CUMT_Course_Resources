#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string* s = new string[N];
	for (int i = 0; i < N; i++)
		cin >> s[i];
	int* p = new int[N];
	for (int i = 0; i < N; i++)
		p[i] = 0;
	for(int i=0;i<N-1;i++)
		for (int j = 0; j < N - i - 1; j++) {
			if (s[j] > s[j + 1]) {
				string temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	for (int i = 0; i < N; i++)
		cout << s[i] << " ";

	return 0;
}
