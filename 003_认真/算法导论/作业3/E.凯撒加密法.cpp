#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int k;
        string s;
        cin >> s >> k;
        int sig = k >= 0 ? 1 : -1;
        k = abs(k) % 26;
        k = sig == -1 ? k : 26 - k;
        
        for(char& ch: s){
            if(ch >= 'A' && ch <= 'Z'){
                ch = (ch - 'A' + k) % 26 + 'A';
            }
            else if(ch >= 'a' && ch <= 'z'){
                ch = (ch - 'a' + k) % 26 + 'a';
            }
        }
        cout << s << endl;
    }
    
}