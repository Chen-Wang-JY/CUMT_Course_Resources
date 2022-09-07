#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int r = b;
    b = a;
    a = r;
}
int main()
{
    int a[10], b[10];
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < 10; i++)
        cin >> b[i];
    int a_max = a[0], a_min = a[0], b_max = b[0], b_min = b[0];

    for (int i = 0; i < 10; i++) 
        for (int j = i + 1; j < 10; j++) 
            if (a[j] < a[i]) 
                swap(a[i], a[j]);

    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
            if (b[i] < b[j])
                swap(b[j], b[i]);

    int c[20];
    for (int i = 0; i < 10; i++)
        c[i] = a[i];
    for (int i = 10, j = 9; i < 20; i++, j--)
        c[i] = b[j];
    for (int i = 0; i < 20; i++)
        for (int j = i + 1; j < 20; j++)
            if (c[i] > c[j])
                swap(c[i], c[j]);

    cout << a[9] << " " << a[0] << endl;
    cout << b[0] << " " << b[9] << endl;
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << b[i] << " ";
    cout << endl;
    for (int i = 0; i < 20; i++)
        cout << c[i] << " ";
    return 0;
}

