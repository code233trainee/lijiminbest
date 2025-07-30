#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    // 周期长度
    long long P = 2 * N - 2;
    // 将报数 1 对应到 0
    long long m = M - 1;
    // 在周期内的位置
    long long r = m % P;

    long long ans;
    if (r < N) {
        // 从左往右
        ans = r + 1;
    } else {
        // 从右往左
        long long rp = r - (N - 1);
        ans = N - rp;
    }

    cout << ans << "\n";
    return 0;
}
