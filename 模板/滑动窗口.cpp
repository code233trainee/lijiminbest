#include <bits/stdc++.h>
using namespace std;
#define ll long long

//O(n)
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
    return 0;
}