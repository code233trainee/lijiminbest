// https://codeforces.com/problemset/problem/2061/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> ma;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    bool ok = false;
    ll x = -1, y = -1;
    for(auto it = ma.rbegin(); it != ma.rend(); ++it)
    {
        x = it->first;
        y = it->second;
        if(y >= 2)
        {
            if(y >= 4)
            {
                cout << x << " " << x << " " << x << " " << x << "\n";
                return;
            }
            ma[x] -= 2;
            if(ma[x] == 0)
            {
                ma.erase(x);
            }
            ok = true;
            break;
        }
    }
    if(!ok)
    {
        cout << -1 << endl;
        return;
    }
    for(auto it = ma.begin(); it != ma.end(); it++)
    {
        ll z = it->first;
        ll k = it->second;
        if(k >= 2)
        {
            cout << x << " " << x << " " << z << " " << z << "\n";
            return;
        }
        else if((++it) != ma.end())
        {
            ll u = it->first;
            ll v = it->second; 
            if(k > 0 && v > 0 && abs(z - u) < x*2)
            {
                cout << z << " " << u << " " << x << " " << x << "\n";
                return;
            }
            else
            {
                it--;
            }
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}