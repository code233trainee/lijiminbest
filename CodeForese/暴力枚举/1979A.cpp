#include <bits/stdc++.h>
void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int mx = INT_MAX;
    for(int i = 0; i < n - 1; i++)
    {
        int temp = std::max(a[i], a[i+1]);
        if(temp < mx)
        {
            mx = temp;
        }
    }
    std::cout << mx-1 << "\n";
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