#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    ll L = -1, R = -1;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] > 0)
        {
            if(L == -1)
            {
                L = i;
            }
            R = i;
        }
    }
    if(L == -1)
    {
        for(ll i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        return 0;
    }
    for(ll i = L-1; i >= 1; i--)
    {
    	a[i] = a[i+1] + 1;
	}
	for(ll i = R+1; i <= n; i++)
	{
		a[i] = a[i-1] + 1;
	}
	for(ll i = 1; i <= n; i++)
	{
		if(a[i] > 0)
		{
			continue;
		}
		ll j = i;
		while(j <= n && a[j] == 0)
		{
			j++;
		}
		if(a[i-1] < a[j])
		{
			while(j > i && a[j] > a[i-1])
			{
				j--;
				a[j] = a[j+1]-1;
			}
			for(ll k = i, f = 1; k < j; k++, f ^= 1)
			{
				a[k] = a[i-1] + f;
			}
		}
		else
		{
			while(i < j && a[i-1] > a[j])
			{
				a[i] = a[i-1] - 1;
				i++;
			}
			for(ll k = i, f = 1; k < j; k++, f ^= 1)
			{
				a[k] = a[j] + f;
			}
		}
	}
    for(ll i = 1; i <= n-1; i++)
    {
        if(abs(a[i] - a[i+1]) != 1)
        {
            cout << "-1\n";
            return 0;
        }
    }
    for(ll i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i==n];
    }
    return 0;
}
