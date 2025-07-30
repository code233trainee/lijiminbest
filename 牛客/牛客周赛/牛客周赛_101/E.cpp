#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    const double ln2 = std::log(2.0);
    double ans = 0.0;

    for(int i = 1; i < n; i++){
        double dx = x[i] - x[i-1];
        double dy = y[i] - y[i-1];
        double e = std::hypot(dx, dy);

        double e_ln2 = e * ln2;
        if (e_ln2 < 1.0) {
            // 最优 k = 0
            ans += 2.0 * e;
        } else {
            // 最优 k = log2(e * ln2)
            // t = 2*log2(e*ln2) + 2/ln2
            double t = 2.0 * (std::log(e_ln2) / ln2) + 2.0 / ln2;
            ans += t;
        }
    }

    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}
