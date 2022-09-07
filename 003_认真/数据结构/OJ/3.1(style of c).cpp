#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	char ch[20][1010], temp[1010];
	for (int i = 0; i < N; i++)
		cin >> ch[i];
	for(int i=0;i<N-1;i++)
		for (int j = 0; j < N - i - 1; j++) {
			if (strcmp(ch[j],ch[j+1])) {
				strcpy(temp, ch[j]);
				strcpy(ch[j], ch[j + 1]);
				strcpy(ch[j + 1], temp);
			}
		}
	for (int i = 0; i < N; i++)
		cout << ch[i] << " ";

	return 0;
}
