#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 998244353;

int64 modpow(int64 a, int64 e=MOD-2){
    int64 r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> byR(m+1);
    vector<int64> u(n);
    int64 B = 1;

    for(int i = 0; i < n; i++){
        int l, r;
        int64 p, q;
        cin >> l >> r >> p >> q;
       
        int64 invq = modpow(q);
        int64 w = p * invq % MOD;
        
        int64 one_minus_w = (1 - w + MOD) % MOD;
       
        B = B * one_minus_w % MOD;
      
        u[i] = w * modpow(one_minus_w) % MOD;
        byR[r].emplace_back(l, i);
    }

    
    vector<int64> dp(m+1, 0);
    dp[0] = 1;
    for(int x = 1; x <= m; x++){
        int64 s = 0;
        
        for(auto &pr : byR[x]){
            int l = pr.first, idx = pr.second;
            s = (s + dp[l-1] * u[idx]) % MOD;
        }
        dp[x] = s;
    }
    int64 F = dp[m];
    int64 ans = B * F % MOD;
    cout << ans << "\n";
    return 0;
}
