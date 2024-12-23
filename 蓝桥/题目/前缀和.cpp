#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
// https://www.lanqiao.cn/problems/359/learning/
using ll = long long;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].second;
    }
    ll ans = 0;
    
    // for(int i = 1; i <= n-2; i++)
    // {
    //     for(int j = 1; (j*2 + i) <= n; j++)
    //     {
    //         int temp = i + 2*j;
    //         if(a[i].second == a[temp].second)
    //         {
    //             ans += ((i + temp) * (a[i].first + a[temp].first)) % mod; 
    //         }
    //     }
    // }
    cout << ans%mod << "\n";
    return 0;
}