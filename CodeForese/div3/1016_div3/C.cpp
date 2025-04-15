#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPrime(long long n) {
    if (n < 2) return false;
    // 从 2 到 sqrt(n) 遍历
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // 找到因子则不是质数
    }
    return true;
}
void solve()
{
    ll x, k;
    cin >> x >> k;
    if(x == 1)
    {
        if(k == 2)
        {
            cout << "YES" << "\n"; 
        }
        else
        {
            cout << "NO" << "\n";
        }
        return;
    }
    if(k > 1)
    {
        cout << "NO" << "\n";
        return;
    }
    if(isPrime(x))
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}