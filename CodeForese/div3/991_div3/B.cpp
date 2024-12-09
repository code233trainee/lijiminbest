#include <bits/stdc++.h>
using namespace std;
void solve()
{
    // int n;
    // cin >> n;
    // long long total = 0;
    // vector<int> v(n+1);
    // for(int i = 1; i <= n; i++)
    // {
    //     cin >> v[i];
    //     total += v[i];
    // }
    // if(total%n != 0)
    // {
    //     cout << "NO\n";
    //     return;
    // }
    // long long tar = total / n;  
    // for (int i = 2; i <= n - 1; i++) {
    //     if(v[i-1] > tar)
    //     {
    //         int tt = abs(tar - v[i-1]);
    //         v[i-1] -= tt;
    //         v[i+1] += tt;
    //         continue;
    //     }
    //     else if(v[i-1] < tar)
    //     {
    //         int ta = abs(tar - v[i-1]);
    //         v[i-1] += ta;
    //         v[i+1] -= ta;
    //         continue;
    //     }
    //     if(v[i+1] > tar)
    //     {
    //         int tb = abs(tar - v[i-1]);
    //         v[i-1] += tb;
    //         v[i+1] -= tb;
    //     }
    //     else if(v[i+1] < tar)
    //     {
    //         int tc = abs(tar - v[i-1]);
    //         v[i-1] -= tc;
    //         v[i+1] += tc;
    //     }
    // }
    // int d = v[1];
    // for(int i = 1; i <= n; i++)
    // {
    //     if(v[i] != d)
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    // cout << "YES\n";


    //tourist
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum[2] = {0, 0};
    long long cnt[2] = {0, 0};
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i % 2] += a[i];
        cnt[i % 2] += 1;
    }
    if(sum[0] % cnt[0] == 0 && sum[1] % cnt[1] == 0 && sum[0] / cnt[0] == sum[1] / cnt[1]){
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
