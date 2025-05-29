// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T; 
//     cin >> T;
//     while(T--){
//         int n;
//         cin >> n;
//         vector<pair<ll,ll>> a(n);
//         vector<ll> xs(n), ys(n);
//         for(int i = 0; i < n; i++){
//             cin >> a[i].first >> a[i].second;
//             xs[i] = a[i].first;
//             ys[i] = a[i].second;
//         }
//         sort(xs.begin(), xs.end());
//         sort(ys.begin(), ys.end());
//         ll X1 = xs.front(), XN = xs.back();
//         ll Y1 = ys.front(), YN = ys.back();
//         ll fullW = XN - X1 + 1, fullH = YN - Y1 + 1;
//         ll ans = fullW * fullH;

//         ll cnt_x1 = count(xs.begin(), xs.end(), X1);
//         ll cnt_xn = count(xs.begin(), xs.end(), XN);
//         ll cnt_y1 = count(ys.begin(), ys.end(), Y1);
//         ll cnt_yn = count(ys.begin(), ys.end(), YN);

//         ll X2 = xs.size()>1? xs[1] : X1;
//         ll XN1 = xs.size()>1? xs[n-2] : XN;
//         ll Y2 = ys.size()>1? ys[1] : Y1;
//         ll YN1 = ys.size()>1? ys[n-2] : YN;

//         vector<int> cand;
//         for(int i = 0; i < n; i++){
//             auto [x,y] = a[i];
//             if ((x==X1 && cnt_x1==1)
//              || (x==XN && cnt_xn==1)
//              || (y==Y1 && cnt_y1==1)
//              || (y==YN && cnt_yn==1)) {
//                 cand.push_back(i);
//             }
//         }
//         sort(cand.begin(), cand.end());
//         cand.erase(unique(cand.begin(), cand.end()), cand.end());

//         for(int i: cand){
//             ll nx1 = X1, nxn = XN, ny1 = Y1, nyn = YN;
//             auto [x,y] = a[i];
//             if (x==X1 && cnt_x1==1) nx1 = X2;
//             if (x==XN && cnt_xn==1) nxn = XN1;
//             if (y==Y1 && cnt_y1==1) ny1 = Y2;
//             if (y==YN && cnt_yn==1) nyn = YN1;

//             ll w = nxn - nx1 + 1;
//             ll h = nyn - ny1 + 1;
//             ll area_rest = w * h;
//             ll best;
//             if (area_rest > n-1) {
//                 best = area_rest;
//             } else {
//                 best = min((w+1)*h, w*(h+1));
//             }
//             ans = min(ans, best);
//         }

//         cout << ans << "\n";
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<int> x(n+1), y(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }
    ll mnx = 1, mny = 1, mxx = 1, mxy = 1;
    for(int i = 1; i <= n; i++)
    {
        if(x[i] > x[mxx]) mxx = i;
        if(x[i] < x[mnx]) mnx = i;
        if(y[i] > y[mxy]) mxy = i;
        if(y[i] < y[mny]) mny = i;
    }

    auto get_cost = [&] (ll id) -> ll {
        ll t = (id == 1 ? 2 : 1);
        ll mx = t, nx = t, my = t, ny = t;
        for(int i = 1; i <= n; i++)
        {
            if(i == id) continue;
            if(x[i] > x[mx]) mx = i;
            if(x[i] < x[nx]) nx = i;
            if(y[i] > y[my]) my = i;
            if(y[i] < y[ny]) ny = i;
        }
        ll dx = x[mx] - x[nx] + 1;
        ll dy = y[my] - y[ny] + 1;
        if(dx * dy == n - 1)
        {
            return min((dx+1) * dy, dx * (dy + 1));
        }
        else
        {
            return dx * dy;
        }
    };
    
    ll ans = 1e18;
    ans = min(ans, get_cost(mxx));
    ans = min(ans, get_cost(mnx));
    ans = min(ans, get_cost(mxy));
    ans = min(ans, get_cost(mny));

    cout << ans << endl;

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}