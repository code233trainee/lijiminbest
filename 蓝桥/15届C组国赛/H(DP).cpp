// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<ll> a(1005);
//     vector<ll> dp(1005);
//     for(int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     for(int i = 1; i <= n; i++)
//     {
//         for(int j = m; j >= 0; j--)
//         {
//             ll x = a[i];
//             for(int k = 0; k <= min(j, 31); k++)
//             {
//                 dp[j] = max(dp[j], dp[j - k] + x);
//                 x = (x << 1) | (x >> 31 & 1);
//             }
//         }
//     }
//     ll ans = 0;
//     for(int i = 0; i <= m; i++)
//     {
//         ans = max(ans, dp[i]);
//     }
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n, m; unsigned a[N]; ll f[N], ans;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; ~j; j--) {
			unsigned x = a[i];
			for (int k = 0, u = min(j, 31); k <= u; k++) {
				f[j] = max(f[j], f[j - k] + x);
				x = x << 1 | (x >> 31 & 1);
			}
		}
	}
	for (int i = 0; i <= m; i++) ans = max(ans, f[i]);
	cout << ans;
}