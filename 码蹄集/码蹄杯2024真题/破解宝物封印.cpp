#include <bits/stdc++.h>
using namespace std;

// 模板：预处理阶乘和逆元，计算 C(n, k) % MOD

static const int MAXN = 1000000;    // 根据题目调整最大 n
static const int MOD = 1000000007;

long long fac[MAXN + 1], inv_fac[MAXN + 1];

// 快速幂计算 a^b % MOD
long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 预处理阶乘和阶乘的逆元
void init_factorials(int n = MAXN) {
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    // inv_fac[n] = (fac[n])^{-1}
    inv_fac[n] = modpow(fac[n], MOD - 2);
    for (int i = n; i >= 1; --i) {
        inv_fac[i - 1] = inv_fac[i] * i % MOD;
    }
}

// 计算 C(n, k) % MOD
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 示例：初始化，并回答多组查询
    init_factorials();
    int n, k;
    cin >> n >> k;
    cout << comb(n, k) << "\n";

    return 0;
}
