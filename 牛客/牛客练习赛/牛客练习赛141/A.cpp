#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    ll sum1 = 0;
    ll sum2 = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            sum1 += a[i];
        }
        else
        {
            sum2 += a[i];
        }
    }
    cout << sum1 << " " << sum2 << endl;
    return 0;
}