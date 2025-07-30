#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    if(l == r)
    {
        if(n % 2 == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << l << endl;
        }
    }
    else
    {
        if(n == 1)
        {
            cout << l << endl;
        }
        else
        {
            if(n % 2 == 1)
            {
                cout << l << endl;
            }
            else
            {
                if(n == 2)
                {
                    cout << -1 << endl;
                    return;
                }
                ll f = 1;
                ll temp = l;
                while(temp)
                {
                    temp >>= 1;
                    f <<= 1;
                }
                if(f <= r)
                {
                    if(k <= n-2)
                    {
                        cout << l << endl;
                    }
                    else
                    {
                        cout << f << endl;
                    }
                }
                else
                {
                    cout << -1 << endl;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}