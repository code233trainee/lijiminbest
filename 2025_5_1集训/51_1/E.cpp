// https://codeforces.com/problemset/problem/1733/C
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<pair<int, int>> vp;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << 0 << endl;
        return;
    }
    else if(n == 2)
    {
        if(a[1] > a[2])
        {
            cout << 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return ;
    }
    vp.push_back({1, n});
    if((a[1] + a[n]) & 1)
    {
        a[n] = a[1];
    }
    else
    {
        a[1] = a[n];
    }
    for(int i = 2; i < n; i++)
    {
        if((a[i] + a[1]) % 2 != 0)
        {
            vp.push_back({1, i});
        }
        else
        {
            vp.push_back({i, n});
        }
    }
    cout << vp.size() << endl;
    for(int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;;
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