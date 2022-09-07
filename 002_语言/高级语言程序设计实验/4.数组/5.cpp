#include <iostream>
#include<string>
using namespace std;
int main()
{
    char s[50];
    cin.getline(s, 50, '.');
    int i = 0, count=0;
    while (s[i] != '\0') {
        if (s[i] != ' ')
            cout << s[i];
        else {
            cout << endl;
            count++;
        }
        i++;
    }
    cout << count;
    return 0;
}

