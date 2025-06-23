#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll n)
{
    ll a = sqrt(n*(n+1)/2);
    ll b = n*(n+1)/2;
    return (a*a == b);
}
void solve()
{
    ll n;
    cin >> n;
    if(check(n))
    {
        cout << "-1\n";
        return;
    }
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if(check(i))
        {
            swap(a[i], a[i+1]);
            i++;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
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