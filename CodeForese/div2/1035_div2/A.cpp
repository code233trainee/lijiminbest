#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    ll ans = 0;
    if(b % 2 == 1)
    {
        if(a > b)
        {
            ans = -1;
        }
        else
        {
            for(int i = a; i < b; i++)
            {
                if(i % 2 == 0)
                {
                    ans += min(x, y);
                }
                else
                {
                    ans += x;
                }
            }
        }
    }
    else
    {
        if(a > b)
        {
            if(a - 1 == b)
            {
                ans = y;
            }
            else
            {
                ans = -1;
            }
        }
        else
        {
            for(int i = a; i < b; i++)
            {
                if(i % 2 == 0)
                {
                    ans += min(x, y);
                }
                else
                {
                    ans += x;
                }
            }
        }
    }
    cout << ans << endl;
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