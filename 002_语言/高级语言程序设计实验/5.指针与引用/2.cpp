#include <iostream>
#include<string>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int** p = new int*[m];
	for (int i = 0; i < m; i++)
		p[i] = new int[n];
	int** q = new int* [n];
	for (int i = 0; i < n; i++)
		q[i] = new int[m];

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin >> p[i][j];

	for (int i = 0; i < m; i++)
		for (int j = 0, k = 0; j < n; j++, k++) {

			q[k][i] = p[i][j];
		}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << q[i][j] << " ";
		cout << endl;
	}


	return 0;
}


