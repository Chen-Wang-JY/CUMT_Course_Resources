#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define MOD 100000007
typedef long long ll;
ll qpow(ll num, ll n)
{
    if (n == 0)
    
        return 1;
    else if (n % 2 == 1)
        return qpow(num, n - 1) * num % MOD;
    else{
        ll temp = qpow(num, n / 2) % MOD;
        return temp * temp % MOD;
    }
}

int main()
{
    int ans[25010];
    ans[1] = 1;
    for(int i = 2; i <= 25000; i++)
        ans[i] = (ans[i - 1] + qpow(i, i)) % MOD;

    int x;
    while(cin >> x){
        cout<<(ans[x] + 1) % MOD<<endl;
    }
    return 0;
}