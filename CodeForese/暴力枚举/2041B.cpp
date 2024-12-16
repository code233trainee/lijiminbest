#include <bits/stdc++.h>
#define ll long long

void solve()
{
    ll w, b, i;
    std::cin >> w >> b;
    w += b;
    //注意这里的退出条件
    //剩下的不够一排的时候就退出
    for(i = 1; i <= w; i++)
    {
        w -= i;
    }
    //因为是先加了再判断
    //所以要减一
    std::cout << i-1 << "\n";
}
int main()
{
    int t;

    std::cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}