#include <bits/stdc++.h>
bool cmp(int a, int b)
{
    return a > b;
}
void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n - 1; i++)
    {
        if(a[0] % a[i + 1] != 0)
        {
            std::cout << "No\n";
            return;
        }
    }
    std::cout << "Yes\n";
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