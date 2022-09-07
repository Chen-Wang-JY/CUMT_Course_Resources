#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long factorial(long number)
{
	if (number <= 1)
		return 1;
	else
		return number * factorial(number - 1);
}

int combinator(int n, int m)
{
	int temp;
	if (n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}
	return factorial(n) / (factorial(m) * factorial(n - m));
}
int main()
{
	cout << combinator(4, 2) << " " << combinator(5, 2) << endl;
	return 0;
}
