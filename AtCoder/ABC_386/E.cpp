#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> suf(n + 1);
    for(int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] ^ a[i];
    }
    
    ll ans = 0;
    auto dfs = [&](auto &&self, int i, int k, ll x) {
        if(k == 0)
        {
            ans = max(ans, x);
            return;
        }
        if(i + k == n)
        {
            ans = max(ans, x ^ suf[i]);
            return;
        }
        self(self, i + 1, k, x);
        self(self, i + 1, k - 1, x ^ a[i]);
    };
    dfs(dfs, 0, k, 0ll);

    cout << ans << "\n";
    return 0;
}