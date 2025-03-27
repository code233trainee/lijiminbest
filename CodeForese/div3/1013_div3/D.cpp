#include <iostream>
using namespace std;
using ll = long long;
// 计算在一行中，m个位置内，允许最长连续桌子不超过 L 时最多能放桌子的数量
ll check(ll m, ll L) {
    ll blocks = (m + 1) / (L + 1);          // 能放多少完整的组
    ll r = (m + 1) % (L + 1);                 // 剩余的槽位数
    ll extra = (r > 0 ? r - 1 : 0);           // 最后一组可额外放的桌子数
    return blocks * L + extra;
}
 
// 二分查找最小的 L，使得 n * f(m, L) >= k
void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    ll lo = 1, hi = m;
    ll ans = m; 
    
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll total = n * check(m, mid);
        if (total >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    
    cout << ans << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
