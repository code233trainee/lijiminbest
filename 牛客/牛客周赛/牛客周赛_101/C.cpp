#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    ll res = 1;
    while(res <= n)
    {
        res = res << 1;
    }
    cout << res - 1 << endl;
    return 0;
}