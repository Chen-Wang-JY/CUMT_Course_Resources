#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    string k;
    string C;
    cin >> k >> C;
    int i = 0;
    while(k.size() < C.size()){
        k.push_back(k[i++]);
    }
    string ans = "";
    for(int i = 0; i < C.size(); i++){
        int key = (k[i] >= 'A' && k[i] <= 'Z') ? k[i] - 'A' : k[i] - 'a';
        int temp = (C[i] >= 'A' && C[i] <= 'Z') ? 
                    (C[i] - key) < 'A' ? C[i] - key + 26 : C[i] - key : 
                    (C[i] - key) < 'a' ? C[i] - key + 26 : C[i] - key;
        ans.push_back(temp);
    }
    cout << ans << endl;
    return 0;
}