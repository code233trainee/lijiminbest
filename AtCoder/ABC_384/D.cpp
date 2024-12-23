#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool hasSubarrayWithSum(vector<ll> &arr, ll sum)
{
    ll l = 0;
    ll total = 0;
    for(ll r = 0; r < arr.size(); r++)
    {
        total += arr[r];
        while(total > sum && l <= r)
        {
            total -= arr[l++];
        }
        if(total == sum)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < n; i++)
    {
        a.push_back(a[i]);
    }
    if(s > sum)
    {
        s = s % sum;
    }
    if(hasSubarrayWithSum(a, s))
    {
        cout << "Yes\n"; 
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}