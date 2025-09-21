//https://codeforces.com/contest/2133/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    set<int> se;
    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(se.count(x))
        {
            ok = true;
        }
        se.insert(x);
    }
    cout << (ok ? "YES" : "NO") << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}