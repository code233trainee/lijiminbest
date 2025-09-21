#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct point
{
    int x, y;
};
void solve()
{
    int n;
    cin >> n;
    vector<point> a(n);
    map<pair<int, int>, int> cnt;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        cnt[{a[i].x, a[i].y}]++;
    }
    sort(a.begin(), a.end(), [&](auto X, auto Y) -> bool {
        return X.x < Y.x;
    });
    ll ans = 0;
    map<int, int> mpy;
    for(int i = 0; i < n; i++)
    {
        if(cnt.count({a[i].x,a[i].y+1}))
        {
            ans += mpy[a[i].y];
            mpy[a[i].y]++;
        }
    }

    sort(a.begin(), a.end(), [&](auto X, auto Y) -> bool {
        return X.y < Y.y;
    });

    
    map<int, int> mpx;
    for(int i = 0; i < n; i++)
    {
        if(cnt.count({a[i].x+1, a[i].y}))
        {
            ans += mpx[a[i].x];
            mpx[a[i].x]++;
        }
    }
    ll c = 0;
    for(int i = 0; i < n; i++)
    {
        if(cnt.count({a[i].x + 1, a[i].y}) && cnt.count({a[i].x, a[i].y + 1}) && cnt.count({a[i].x+1, a[i].y+1}))
        {
            c++;
        }
    }
    cout << ans - c << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}