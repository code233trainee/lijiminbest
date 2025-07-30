#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    set<int> b;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > a[k])
        {
            b.insert(a[i]);
        }
    }
    if(b.empty())
    {
        cout << "YES\n";
    }
    else
    {
        int hig = 0;
        int now = a[k];
        for(auto z : b)
        {
            if(z - now <= now - hig)
            {
                hig += z - now;
                now = z;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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