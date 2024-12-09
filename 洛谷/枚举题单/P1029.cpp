#include <bits/stdc++.h>
#define ll long long
ll gcd(ll a, ll b) 
{
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//两个数的积等于它们最大公约数和它们最小公倍数的积
int main()
{
    ll m, n, ans = 0;
    std::cin >> m >> n;
    if(m == n)
    {
        ans--;
    }
    n *= m;
    for(ll i = 1; i <= sqrt(n); i++)
    {
        if(n%i == 0 && gcd(i, n/i)==m)//这里实际上还是求出了另一个值
        {
            ans += 2;
        }
    }
    std::cout << ans;
    return 0;
}