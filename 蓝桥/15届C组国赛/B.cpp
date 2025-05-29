#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main()
{
    ll ans = 0;
    for(int x = 1; x < 20240601; x++)
    {
        for(int y = x+1; y <= 20240601; y++)
        {
            if(x == y) continue;
            ll x1 = (ll)pow(x, x);
            ll y1 = (ll)pow(y, y);
            ll sum = x1 + y1;
            if(sum % 6421 == 0)
            {
                ans++;
            } 
        }
    }
    cout << ans;
    return 0;
}