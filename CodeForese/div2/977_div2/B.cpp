#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x <= n)
        {
            cnt[x]++;
        }
    }
    int i = 0;
    for(i = 0; i <= n; i++)
    {
        if(cnt[i] == 0)
        {
            break;
        }
        if(i + x <= n)
        {
            cnt[i+x] += cnt[i] - 1;
        }
    }
    cout << i << endl;
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
