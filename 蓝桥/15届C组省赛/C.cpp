#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    ll cnt = 0;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if((a[i] & (a[i]-1)) == 0)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    // vector<int> a(10000);
    // for(int i = 1; i <= 1000; i++)
    // {
    //     for(int j = i + 1; j <= 1000; j++)
    //     {
    //         int temp = (j - i + 1) * (i + j) / 2;
    //         if(temp <= 1000)
    //         {
    //             a[temp] = 1;
    //         }
    //     }
    // }
    // for(int i = 1; i <= 1000; i++)
    // {
    //     if(a[i] == 1)
    //     {
    //         continue;
    //     }
    //     cout << i << endl;
    // }
    return 0;
}