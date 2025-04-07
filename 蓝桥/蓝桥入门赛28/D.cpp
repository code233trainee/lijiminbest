#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(n < 2 && a[0] != m)
    {
        cout << "NO" << endl;
        return;
    }
    bool ok1 = false;
    bool ok2 = false;
    bool ok3 = false;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == m)
        {
            ok3 = true;
        }
        if(a[i] < m)
        {
            ok1 = true;
        }
        if(a[i] > m)
        {
            ok2 = true;
        }
    }
    if((ok1 && ok2) || ok3)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
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