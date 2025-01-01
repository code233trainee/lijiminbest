#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll temp = k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    int i = 0;
    for( i = 1; i <= n; i++)
    {
        //每次都要按下一次柠檬水为0的按钮才能排除
        //所以我们的答案就是需要的柠檬水的数量加上当前计算的i减1
        k -= (a[i] - a[i-1]) * (n - i + 1);
        if(k <= 0)
        {
            break;
        }
    }
    cout << temp + i - 1 << "\n";
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}