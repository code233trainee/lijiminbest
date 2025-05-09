#include <bits/stdc++.h>

int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> S(N);
    std::vector<int> C(N);
    std::vector<double> P(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> S[i] >> C[i] >> P[i];
        P[i] /= 100.0;
    }

    std::vector<std::vector<double>> dp(1 << N, std::vector<double>(X + 1, 0.0));

    for (int x = 0; x <= X; ++x) {
        for (int s = 0; s < (1 << N); ++s) {
            for (int i = 0; i < N; ++i) {
                int xx = x - C[i];
                int ss = s | (1 << i);
                if (xx < 0 || s == ss) {
                    continue;
                }
                double val = P[i] * (dp[ss][xx] + S[i]) + (1 - P[i]) * dp[s][xx];
                dp[s][x] = std::max(dp[s][x], val);
            }
        }
    }

    std::cout << std::fixed << std::setprecision(12);
    std::cout << dp[0][X] << std::endl;

    return 0;
}    