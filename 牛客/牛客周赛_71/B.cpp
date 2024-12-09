#include <bits/stdc++.h>
void solve()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if(n == 2 && s[0] != s[1])
    {
        std::cout << -1 << "\n";
        return;
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