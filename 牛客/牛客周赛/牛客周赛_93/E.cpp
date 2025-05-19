#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // 1) 统计频次
    vector<int> cnt(n+1, 0);
    for(int v : a){
        cnt[v]++;
    }

    // 2) 预计算 2^i mod
    vector<ll> pw(n+1, 1);
    for(int i = 1; i <= n; i++){
        pw[i] = (pw[i-1] * 2) % MOD;
    }

    // 3) 计算 f[v] = 2^{cnt[v]} - 1
    vector<ll> f(n+1, 0);
    for(int v = 0; v <= n; v++){
        if(cnt[v] > 0){
            f[v] = (pw[cnt[v]] - 1 + MOD) % MOD;
        }
        // 否则 f[v]=0 保持
    }

    // 4) S_const = 所有常量子序列数量之和
    ll S_const = 0;
    for(int v = 0; v <= n; v++){
        S_const = (S_const + f[v]) % MOD;
    }

    // 5) 找最大的 ℓ 使得 cnt[0..ℓ] 全部 >0
    int ell = 0;
    while(ell <= n && cnt[ell] > 0) {
        ell++;
    }
    // 最终 ell 是第一个 cnt[ell]==0 的位置，
// 因此合法的 M = 1..ell-1
    ell = max(ell-1, 0);

    // 6) 计算前缀乘积 P[M] 并累加 S_nonconst
    ll prefix = 1;
    ll S_nonconst = 0;
    for(int M = 0; M <= ell; M++){
        prefix = (prefix * f[M]) % MOD;
        if(M >= 1){
            S_nonconst = (S_nonconst + prefix) % MOD;
        }
    }

    // 7) 最终答案
    ll ans = (S_const + S_nonconst) % MOD;
    cout << ans << "\n";
    return 0;
}
