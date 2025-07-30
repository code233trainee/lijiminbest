#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 全局最小/最大
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());

        // 前缀最小标记
        vector<bool> isPrefMin(n, false);
        int curMin = INT_MAX;
        for (int i = 0; i < n; i++) {
            curMin = min(curMin, a[i]);
            if (a[i] == curMin) {
                isPrefMin[i] = true;
            }
        }

        // 后缀最大标记
        vector<bool> isSuffMax(n, false);
        int curMax = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            curMax = max(curMax, a[i]);
            if (a[i] == curMax) {
                isSuffMax[i] = true;
            }
        }

        // 构造答案
        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            if (a[i] == mn || a[i] == mx) 
            {
                ans[i] = '1';
            }
            else
            {
                if(isPrefMin[i] && isSuffMax[i])
                {
                    ans[i] = '1';
                }
                else if(!isPrefMin[i] && isSuffMax[i])
                {
                    ans[i] = '1';
                }
                else if(isPrefMin[i] && !isSuffMax[i])
                {
                    ans[i] = '1';
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
