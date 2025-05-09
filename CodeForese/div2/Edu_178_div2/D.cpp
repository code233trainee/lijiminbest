#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 6e6+10;
ll a[N], pre[N], pre_prime[N];
bool prime[N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 大到小排序
    sort(a+1, a+1+n, greater<ll>());

    for(int i = 1; i <= n; i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    int ans = n - 1;
    for(int i = 1; i <= n; i++)
    {
        if(pre[i] < pre_prime[i])
        {
            break;
        }
        ans = n - i;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 2; i < N; i++)
    {
        prime[i] = true;
    }
    for(int i = 2; i < N; i++)
    {
        if(!prime[i])
        {
            continue;
        }
        for(int j = i * 2; j < N; j += i)
        {
            prime[j] = false;
        }
    }
    int cnt = 0;
    for(int i = 2; i < N; i++)
    {
        if(prime[i])
        {
            pre_prime[++cnt] = i;
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        pre_prime[i] += pre_prime[i-1];
    }
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}