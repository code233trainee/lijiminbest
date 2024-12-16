#include <bits/stdc++.h>
void solve()
{
    int n, k;
    std::cin >> n >> k;
    if(n==1)
    {
        std::cout << "0\n";
        return;
    }
    int cnt = 1;
    int i = 1;
    while(cnt < n)
    {
        cnt = i*k-(i-1);
        i++;
    }
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