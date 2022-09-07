#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	float pa = 2.75, pb = 12.5, pc = 26.8, pd = 512;
	if (d > 8)
		pd = 512 * 0.85;
	else if (d > 3 && d <= 8)
		pd = 512 * 0.9;
	float Total_A = pa * a;
	float Total_B = pb * b;
	float Total_C = pc * c;
	float Total_D = pd * d;
	cout << "A:" << Total_A << endl
		<< "B:" << Total_B << endl
		<< "C:" << Total_C << endl
		<< "D:" << Total_D << endl
		<< "total:" << Total_A + Total_B + Total_C + Total_D << endl;
	return 0;
}