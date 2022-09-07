#include <iostream>
#include<string>
using namespace std;
void split(double x, int* iPart, double* fPart) {
	int z = int(x);
	double xiao = x - z;
	*iPart = z;
	*fPart = xiao;
}
int main()
{
	double x;
	cin >> x;
	int* iPart=new int;
	double* fPart=new double;
	split(x, iPart, fPart);
	cout << *iPart << endl << *fPart << endl;
	return 0;
}


