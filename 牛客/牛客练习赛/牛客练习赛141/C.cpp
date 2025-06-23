#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    ll x;
    cin >> s >> x;
    int n = s.size();

    // cnt[c] = 当前窗口内字符 'a'+c 的个数
    vector<ll> cnt(26, 0);
    ll inv = 0;           // 当前窗口的逆序对数
    ll ans = LLONG_MAX;   // 最终答案

    int l = 0;
    for (int r = 0; r < n; r++) {
        int c = s[r] - 'a';
        // 扩右端点，计算 s[r] 与窗口内大于它的字符构成的逆序对
        for (int ch = c + 1; ch < 26; ch++) {
            inv += cnt[ch];
        }
        cnt[c]++;

        // 只要 inv >= x，就尝试收缩左端点
        while (l <= r && inv >= x) {
            // 更新答案（当前 inv ≥ x）
            ans = min(ans, inv - x);

            int d = s[l] - 'a';
            // 从窗口里去掉 s[l]
            cnt[d]--;
            // 去掉它与窗口内比它小的字符间原有的逆序对
            for (int ch = 0; ch < d; ch++) {
                inv -= cnt[ch];
            }
            l++;

            // 移动后，若 inv 仍 ≥ x，下次循环继续收缩
        }

        // 当 inv < x 时，也更新一次答案
        ans = min(ans, x - inv);
    }

    cout << ans << "\n";
    return 0;
}
