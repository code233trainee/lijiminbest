#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 2>>> g(n);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto uwu = [&](int u) -> vector<ll>{
        vector<ll> dis(n, 1e18);
        vector<bool> vis(n);       

        priority_queue<array<ll, 2>> q;
        q.push({0, u});
        while (q.size()){
            auto [d, c] = q.top();
            d = -d;
            q.pop();

            if (vis[c])
                continue;
            vis[c] = true;
            dis[c] = d;

            for (auto [x, w] : g[c]){
                if (vis[x])
                    continue;

                q.push({-max(d, 1LL * w), x});
            }
        }

        return dis;
    };

    ll ans = 1e18;
    vector<ll> dis_s = uwu(0), dis_t = uwu(n - 1);
    for (int u = 0; u < n; u++){
        for (auto [v, w] : g[u]){
            ans = min(ans, {max({dis_s[u], dis_t[v], 1LL * w}) + w});
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}
