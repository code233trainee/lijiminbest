#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    // int n;
    // cin >> n;
    // vector<ll> a(n + 1);
    // // 这里假设 a[i] ≤ n；如果 a[i] 范围更大，可以改成 unordered_map<ll, vector<int>> cnt;
    // vector<vector<int>> cnt(n + 1);
    // // 记录到底出现了哪些不同的值
    // vector<ll> vals;
    // vals.reserve(n);

    // for (int i = 1; i <= n; i++) {
    //     cin >> a[i];
    //     if (cnt[a[i]].empty()) {
    //         // 第一次见到 a[i]，把它记入不同值列表
    //         vals.push_back(a[i]);
    //     }
    //     cnt[a[i]].push_back(i);
    // }

    // if (vals.size() == 1) {
    //     // 全部都是同一个值，直接输出 0
    //     cout << 0 << "\n";
    //     return;
    // }

    // ll ans = LLONG_MAX;
    // // 对于每个不同的值 v，只算一次它的最大连续段
    // for (ll v : vals) {
    //     auto &pos = cnt[v];      // v 出现的所有下标
    //     int k = (int)pos.size();
    //     if (k == 1) {
    //         // 只出现过一次
    //         ll cost = v * (ll)(n - 1);
    //         ans = min(ans, cost);
    //     } else {
    //         // 扫一遍 pos，计算 max_len
    //         int max_len = 1, cur_len = 1;
    //         for (int i = 1; i < k; i++) {
    //             if (pos[i] == pos[i - 1] + 1) {
    //                 cur_len++;
    //             } else {
    //                 cur_len = 1;
    //             }
    //             max_len = max(max_len, cur_len);
    //         }
    //         ll cost = v * (ll)(n - 1 - max_len + 1);
    //         ans = min(ans, cost);
    //     }
    // }

    // cout << ans << "\n";

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 1e18;
    for(int i = 0; i < n;)
    {
        ll ei = i + 1;
        while(ei < n && a[i] == a[ei])
        {
            ei++;
        }
        ll res = a[i] * (i + (n - ei));
        ans = min(ans, res);
        i = ei;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
