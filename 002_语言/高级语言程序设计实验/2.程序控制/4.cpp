#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	float* p = new float[num];
	float* max = &p[0];
	float* min = &p[0];
	float sum = 0;
	for (int i = 0; i < num; i++) {
		cin >> p[i];
		if (*max < p[i])
			max = &p[i];
		if (*min > p[i])
			min = &p[i];
		sum += p[i];
	}
	cout << (sum - *max - *min) / (num - 2);
	return 0;
	
}