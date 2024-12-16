#include <bits/stdc++.h>
bool cmp(int a, int b)
{
    return a > b;
}
void solve()
{
    int n, k;
    std::cin >> n >> k;
    if(k == 0)
    {
        std::cout << 0 << "\n";
        return;
    }
    std::vector<int> a;
    a.push_back(0);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            a.push_back(n);
            continue;
        }
        a.push_back(n-i);
        a.push_back(n-i);
    }
    for(int i = 1; i < a.size(); i++)
    {
        k -= a[i];
        if(k <= 0)
        {
            std::cout << i << "\n";
            return;
        }
    }
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