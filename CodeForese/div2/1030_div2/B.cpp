#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 2LL * n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << ' ' << 1 << ' ' << (n - i + 1) << '\n';
            int l = n - i + 2;
            if (l <= n) {
                cout << i << ' ' << l << ' ' << n << '\n';
            } else {
                cout << i << ' ' << n << ' ' << n << '\n';
            }
        }
    }
    return 0;
}
