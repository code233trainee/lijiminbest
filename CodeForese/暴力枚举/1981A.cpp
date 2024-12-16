#include <bits/stdc++.h>
void solve()
{
    int l, r;
    std::cin >> l >> r;
    //log()是以e为底
    //log10()是以10为底的
    //以x为底的我们可以转化一下=log(r)/log(x);
    //返回值类型为long double
    std::cout << int(log(r)/log(2)) << std::endl;
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