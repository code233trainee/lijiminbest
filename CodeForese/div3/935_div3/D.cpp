#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> A(n), B(n);
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    //翻转整个数组
    reverse(A.begin(), A.end());

    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    reverse(B.begin(), B.end());

    ll bSum = 0;
    ll pref = 0;
    for(ll i = 0; i < n - m; i++)
    {
        if(A[i] < B[i])
        {
            pref += bSum;
            pref += A[i];
            bSum = 0;
        }
        else
        {
            bSum += B[i];
        }
    }

    ll res = 1e18;
    for(ll i = n - m; i < n; i++)
    {
        res = min(res, pref + bSum + A[i]);
        bSum += B[i];
    }
    cout << res << "\n";
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