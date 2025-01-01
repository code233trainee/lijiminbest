#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n*n);
    for(int i = 0; i < n*n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int k = 0;
    ll base = a[0];
    /* 
    *  c < d     c > d
    *  1 4 7  *  1 3 5
    *  3 6 9  *  4 6 8
    *  5 8 11 *  7 9 11
    * (0 3 1 6 4 2 7 5 8)c < d
    * (0 1 3 2 4 6 5 7 8)c > d
    */
    vector<ll> b;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            b.push_back(base+(i*c + j*d));
        }
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n * n; i++)
    {
        if(a[i] != b[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}