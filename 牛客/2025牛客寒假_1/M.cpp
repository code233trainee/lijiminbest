// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// struct ty{
//     ll val, pos;
// };
// bool cmp(ty a1, ty a2)
// {
//     //按照val从小到大排序
//     return a1.val < a2.val;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     vector<ty> a(n+1);
//     vector<ll> b(n+1);
//     for(ll i = 1; i <= n; i++)
//     {
//         ll c;
//         cin >> c;
//         b[i] = c;
//         a[i] = {c, i};
//     }
//     sort(a.begin() + 1, a.end(), cmp);
//     //我们需要找到最小值和次小值的区间
//     ll mx = 0; 
//     ll mi = 0;
//     ll mxl = INT64_MIN;
//     ll mil = INT64_MAX;
//     ll mxr = INT64_MIN;
//     ll mir = INT64_MAX;
//     ll l = INT64_MAX, r = INT64_MIN;
//     ll ans = INT64_MAX;
//     for(int i = 1; i <= n; i++)
//     {
//         l = min(l, a[i].pos);
//         r = max(r, a[i].pos);
//         for(int j = l; j <= r; j++)
//         {
//             mxl = max(mxl, b[j]*2);
//             mil = min(mil, b[j]*2);
//         }
//         if(a[n].pos <= r)
//         {
//             mxr = a[n].val * 2;
//         }
//         else
//         {
//             mxr = a[n].val;
//         }
//         if(i + 1 <= n)
//         {
//             mir = a[i+1].val;
//         }
//         mx = max(mxl, mxr);
//         mi = min(mil, mir);
//         ans = min(ans, mx - mi);
//     }
//     cout << ans;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    pair<ll, ll> a[202020];
    vector<ll> b(202020);
    ll n, i;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }
    a[n].first = 2e9;
    //也是默认从小到大排序
    //先比较first，再比较second
    sort(a, a+n);
    ll l = a[0].second;
    ll r = a[0].second;
    ll ma = max(a[0].first*2, a[n-1].first);
    ll res = ma - min(a[0].first*2, a[1].first);
    for(i = 1; i < n; i++)
    {
        while(a[i].second < l)
        {
            l--;
            ma = max(ma, b[l]*2);
        }
        while(a[i].second > r)
        {
            r++;
            ma = max(ma, b[r]*2);
        }
        res = min(res, ma - min(a[0].first*2, a[i+1].first));
    }
    cout << res;
    return 0;
}