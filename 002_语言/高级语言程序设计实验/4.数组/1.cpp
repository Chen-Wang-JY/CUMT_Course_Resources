#include <iostream>
using namespace std;
int main()
{
    int x[50], y[50];
    int k;
    cin >> k;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        cin >> x[i];
        sum += x[i];
    }
    float ave = float(sum) / k;
    int count = 0;
    for (int i = 0; i < k; i++)
        if (x[i] > ave)
            count++;
    cout << ave << " " << count << " " << endl;
    int ylen = 0;
    for (int i = 0; i < k; i++) {
        bool G = true;
        for (int j = 0; j < ylen; j++)
            if (x[i] == y[j]) {
                G = false;
                break;
            }
        if (G) {
            y[ylen] = x[i];
            cout << y[ylen] << " ";
            ylen++;
        }
    }
    return 0;
}

