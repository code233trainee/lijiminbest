#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 1. 找到最长不重复后缀的起点 r
    unordered_set<int> S_suffix;
    int r = n + 1;
    for (int i = n; i >= 1; i--) {
        if (S_suffix.count(a[i])) {
            break;
        }
        S_suffix.insert(a[i]);
        r = i;
    }

    // 2. 枚举前缀长度，使用双指针维护后缀起点
    unordered_set<int> S_prefix;
    int ans = n - r + 1;  // 只保留后缀的情况

    for (int i = 1; i <= n; i++) {
        // 前缀内部出现重复，则直接结束
        
        if (S_prefix.count(a[i])) {
            break;
        }
        S_prefix.insert(a[i]);

        // 如果 a[i] 在后缀集中出现，就不断收缩后缀
        while (r <= n && S_suffix.count(a[i])) {
            S_suffix.erase(a[r]);
            r++;
        }

        // 更新答案：保留前缀 [1..i] 和后缀 [r..n]
        ans = max(ans, i + (n - r + 1));
    }

    cout << ans << "\n";
    return 0;
}
