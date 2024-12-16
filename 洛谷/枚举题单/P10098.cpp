#include <bits/stdc++.h>
#define ll long long
ll n, p;
bool check (ll x, std::vector<std::vector<ll>> &a)
{
    ll total = 0;
    for(int i = 0; i < n; i++)
    {
        ll temp = 0;
        if(a[i][0] >= x)
        {
            temp = a[i][1] * x;
        }
        else
        {
            temp = a[i][1] * a[i][0] + a[i][2]*(x - a[i][0]);
        }
        // for(int i=0;i<n;i++) {
		// if(x > a[i][0]) total += a[i][1] * a[i][0] + a[i][2] * (x - a[i][0]);
		// else total += a[i][1] * x;
	    // }
        total += temp; 
    }
    return total >= p;
}
int main()
{

    std::cin >> n >> p;
    
    std::vector<std::vector<ll>> a(n, std::vector<ll>(3));
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    
    ll l = 0;
    ll r = 1e12;
    while(l <= r)
    {
        ll mid = l + r >> 1;
        if(check(mid, a))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    std::cout << l << "\n";
    return 0;
}