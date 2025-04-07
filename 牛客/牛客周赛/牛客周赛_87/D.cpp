#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
using ll = long long;
const ll NEG_INF = -1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll total = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    
    // dp[i] 表示前 i 个数字中经过不相交区间删除操作获得的最大收益（收益为删除区间和的负值）
    // 初始 dp[0] = 0，其余设为一个非常小的值
    vector<ll> dp(n+1, NEG_INF);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        // 1. 不删除，直接保留第 i 个数字
        dp[i+1] = max(dp[i+1], dp[i]);
        
        // 2. 如果 i+2 <= n，删除长度为2的区间 [i, i+1]
        if(i + 2 <= n) {
            ll sum2 = a[i] + a[i+1];
            dp[i+2] = max(dp[i+2], dp[i] - sum2);
        }
        
        // 3. 如果 i+3 <= n，删除长度为3的区间 [i, i+2]
        if(i + 3 <= n) {
            ll sum3 = a[i] + a[i+1] + a[i+2];
            dp[i+3] = max(dp[i+3], dp[i] - sum3);
        }
    }
    
    // 最终答案 = total + dp[n] ，即原数组和加上通过删除操作获得的收益
    cout << total + dp[n] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
