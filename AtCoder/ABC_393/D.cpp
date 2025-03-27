#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//储存1的位置
ll b[500005];
int main()
{
    int n;
    string s;
    cin >> n >> s;
    s = ' ' + s;
    vector<ll> a;
    ll cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '1')
        {
            b[++cnt] = i;
        }
    }
    ll mid = (cnt + 1) / 2;
    ll ans = 0;
    for(int i = 1; i <= cnt; i++)
    {
        if(i == mid)
        {
            continue;
        }
        ans += abs(b[mid] - b[i]);
        ans -= 1;
        ans -= abs(mid - i);
        ans += 1;
    }
    cout << ans << "\n";
    return 0;
}