#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        vector<int> l(n+1), r(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
        }
        vector<int> L(n+1), R(n+1);
        L[0] = R[0] = 0;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 0 || d[i] == 1) {
                L[i] = L[i-1] + d[i];
                R[i] = R[i-1] + d[i];
            } else {
                L[i] = L[i-1];
                R[i] = R[i-1] + 1;
            }
            L[i] = max(L[i], l[i]);
            R[i] = min(R[i], r[i]);
            if (L[i] > R[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        // 回溯
        vector<int> h(n+1);
        h[n] = L[n];
        for (int i = n; i >= 1; i--) {
            if (d[i] == 0 || d[i] == 1) {
                h[i-1] = h[i] - d[i];
            } else {
                // 尝试 d[i] = 0
                if (L[i-1] <= h[i] && h[i] <= R[i-1]) {
                    d[i] = 0;
                    h[i-1] = h[i];
                } else {
                    d[i] = 1;
                    h[i-1] = h[i] - 1;
                }
            }
        }
        // 输出结果
        for (int i = 1; i <= n; i++) {
            cout << d[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
