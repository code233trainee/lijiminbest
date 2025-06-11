#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i > 0 && s[i] != s[i-1])
        {
            ans += i + 1;
        }
        else
        {
            ans++;
        }
    }
    cout << ans << endl;
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