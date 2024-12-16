#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = LLONG_MIN;
    ll mn = a[1];
    for(int i = 2; i <= n; i++)
    {
        if(a[i] - mn > ans)
        {
            ans = a[i] - mn;
        }
        if(a[i] < mn)
        {
            mn = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}