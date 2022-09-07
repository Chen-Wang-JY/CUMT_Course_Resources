#include<iostream>
using namespace std;
int length(char* str) {
	int i = 0;
	while (str[i] != NULL)
		i++;
	return i;
}
char* findLast(char* sourceStr, char* subStr) {
	int i = 0,len=length(subStr);
	int position = -1;
	while (sourceStr[i] != NULL) {
		bool r = true;
		for (int j = 0,k=i; j < len; j++,k++)
			if (sourceStr[k] != subStr[j]) {
				r = false;
				break;
			}
		if (r) 
			position = i;
		i++;
	}
	cout << position << endl;
	return NULL;
}
int main()
{
	char sourceStr[100], subStr[20];
	cin >> sourceStr >> subStr;
	findLast(sourceStr, subStr);
	return 0;
}