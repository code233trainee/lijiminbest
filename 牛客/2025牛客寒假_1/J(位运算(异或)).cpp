#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 200005
ll cnt[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        cnt[a]++;
    }
    ll ans = 0;
    for(int i = 1; i < N; i++)
    {
        for(ll j = 1; j <= N; j += i)
        {
            if(!cnt[i])
            {
                continue;
            }
            int x = i ^ j;
            if(x >= N || !cnt[x])
            {
                continue;
            }
            if(gcd(x, i) == j)
            {
                ans += cnt[i] * cnt[x];
            }
        }
    }
    
    cout << ans / 2;
    return 0;
}