#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> segs({{1, -q}, {m, m}, {n + q + 1, n}});
    while(q--)
    {
        int x;
        cin >> x;
        bool ins = false;
        for(auto &[l, r] : segs)
        {
            if(x < l)
            {
                l = max(1, l - 1);
            }
            else if(x > r)
            {
                r = min(n, r + 1);
            }
            else
            {
                ins = true;
                if(l == r)
                {
                    l = n + q;
                    r = -q;
                }
            }
        }
        if(ins)
        {
            segs[0] = {1, max(segs[0].second, 1)};
            segs[2] = {min(segs[2].first, n), n};
        }
        int lf = 0;
        int rg = -1;
        int ans = 0;
        for(auto [l, r] : segs)
        {
            if(l > r)
            {
                continue;
            }
            if(l > rg)
            {
                ans += max(0, rg - lf + 1);
                lf = l;
                rg = r;
            }
            rg = max(rg, r);
        }
        ans += max(0, rg - lf + 1);
        cout << ans << " ";
    }
    cout << "\n";
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