#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] &= 1; // 只保留最低位
    }

    // 预处理前缀和数组
    vector<int> prefix1(n), prefix2(n);
    for (int i = 0; i < n; i++) {
        // 模式1：0, 1, 0, 1, ...
        prefix1[i] = (i == 0 ? 0 : prefix1[i - 1]) + (a[i] != (i % 2));
        // 模式2：1, 0, 1, 0, ...
        prefix2[i] = (i == 0 ? 0 : prefix2[i - 1]) + (a[i] != ((i + 1) % 2));
    }

    int ans = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        int j = i + m - 1;
        // 计算模式1的操作次数
        int cnt1 = prefix1[j] - (i == 0 ? 0 : prefix1[i - 1]);
        // 计算模式2的操作次数
        int cnt2 = prefix2[j] - (i == 0 ? 0 : prefix2[i - 1]);
        // 取最小值
        ans = min(ans, min(cnt1, cnt2));
    }

    cout << ans << endl;
    return 0;
}