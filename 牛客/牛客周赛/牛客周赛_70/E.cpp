#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    //首先确定，对于一个起始点到其他点的最近距离其实就是起始点到其他点的异或(不会经过其他的点)
    if(n % 4 == 0)
    {
        std::cout << n << "\n";
    }
    else if(n % 4 == 1)
    {
        std::cout << "0\n";
    }
    else if(n % 4 == 2)
    {
        std::cout << n + 1 << "\n";
    }
    else
    {
        std::cout << "1\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}