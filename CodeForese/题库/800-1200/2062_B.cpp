// https://codeforces.com/problemset/problem/2062/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        if(y <= i*2 || y <= (n-i-1)*2)
        {
            x = 1;
        }        
    }
    if(x)
    {
        cout << "NO\n";
    }
    else
    {
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