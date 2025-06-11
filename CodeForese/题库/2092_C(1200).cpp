#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> odd;
    vector<ll> even;
    ll sum_odd = 0;
    ll sum_even = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] % 2 == 0)
        {
            even.push_back(a[i]);
            sum_even += a[i];
        }
        else
        {
            odd.push_back(a[i]);
            sum_odd += a[i];
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if(odd.empty())
    {
        cout << even[n-1] << endl;
        return;
    }
    else if(even.empty())
    {
        cout << odd[n-1] << endl;
        return;
    }
    ll ans = 0;
    if(odd.size() == 1 && even.size() == 1)
    {
        cout << sum_even + sum_odd << endl;
        return;
    }
    else
    {
        cout << sum_even-1 + sum_odd - (odd.size() - 2) << endl;
        return; 
    }
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