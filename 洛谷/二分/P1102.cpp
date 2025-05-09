#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, c;
    cin >> n >> c;
    vector<ll> a(n);
    map<ll, ll> cnt;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += cnt[a[i] - c];
    }
    cout << ans << endl;
    return 0;
}