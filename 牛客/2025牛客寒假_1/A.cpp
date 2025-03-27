#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    bool isok = false;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            isok = true;
        }
    }
    if(isok)
    {
        cout << "-1\n";
    }
    else
    {
        //这是一个质数
        cout << int(1e9+7) << "\n";
    }
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
