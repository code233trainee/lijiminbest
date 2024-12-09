#include <bits/stdc++.h>
int main()
{
    int n, k;
    std::cin >> n >> k;
    if(n&1)
    {
        if(n == 1)
        {
            std::cout << "NO\n";
        }
        std::cout << ((n-1) >= k ? "YES" : "NO") << "\n";
    }
    else
    {
        if(n == 2)
        {
            std::cout << (1 >= k ? "YES" : "NO") << "\n";
        }
        std::cout << ((n-1) >= k ? "YES" : "NO") << "\n";
    }
    return 0;
}