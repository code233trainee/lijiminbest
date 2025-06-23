// https://codeforces.com/problemset/problem/2069/b
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n-2);
    for(int i = 0 ; i < n - 2; i++)
    {
        cin >> b[i];
    }
    vector<int> vis;
    for(int i = 0; i < n - 2; i++)
    {
        if(b[i] == 1)
        {
            vis.push_back(i);
        }
    }
    for(int i = 1; i < vis.size(); i++)
    {
        if(vis[i] - 2 == vis[i-1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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