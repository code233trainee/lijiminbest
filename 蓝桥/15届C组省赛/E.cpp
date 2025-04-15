#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll cnt = 0;
    // i, n-i+1
    for(int i = 1; i <= n/2; i++)
    {
        if(i == (n/2))
        {
            cnt += abs(a[i] - a[n-i+1]);
            break;   
        }
        if(a[i] < a[n-i+1])
        {
            ll temp = a[n-i+1] - a[i];
            cnt += temp;
            if(a[i+1] < a[n-i])
            {
                a[i+1] = min(a[n-i], a[i+1]+temp);
            }
        }
        else if(a[i] > a[n-i+1])
        {
            ll temp = a[i] - a[n-i+1];
            cnt += temp;
            if(a[i+1] > a[n-i])
            {
                a[i+1] = max(a[n-i], a[i+1]-temp);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}