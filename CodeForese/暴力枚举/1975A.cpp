#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool ok = true;
    int i = 0;
    for(i = 1; i < n; i++)
    {
        if(a[i] > a[i+1])
        {
            ok = false;
            break;
        }
    }
    if(ok)
    {
        cout << "YES\n";
    }
    else
    {
        int fl = 0;
        for(int j = i + 1; j <= n; j++)
        {
            int k = (j%n)+1;
            if(a[j] > a[k])
            {
                fl = 1;
            }
        }
        if(!fl)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}