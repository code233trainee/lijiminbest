#include <bits/stdc++.h>
#define ll long long
int main()
{
    ll n, m;
    std::cin >> n >> m;
    ll sum1 = 0;
    ll sum2 = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            sum1 += std::min(i, j);//正方形
            sum2 += i*j;//矩形
        }
    }
    std::cout << sum1 << " " << sum2 - sum1 << "\n";
    return 0;
}