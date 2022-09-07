#include<iostream>
using namespace std;
void split(char* str) {
	int max = 0, mindex = 0, index = 0, i = 0, count = 0, r = 0;
	while (str[i] != NULL) {
		if (str[i] == ' ' || str[i] == NULL) {
			count++;
			if (max < r) {
				max = r;
				mindex = index;
			}
			r = 0;
			index = i + 1;
			i++;
			continue;
		}
		r++;
		i++;
	}
	cout << count + 1 << " " << max << " ";
	while (str[mindex] != ' '||str[mindex]==NULL) {
		cout << str[mindex];
		mindex++;
	}
}
int main()
{
	char str[500];
	cin.getline(str, 500);
	split(str);
	return 0;
}