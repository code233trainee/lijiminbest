#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    if(n == 4 || n == 7)
    {
        std::cout << "-1\n";
        return 0;
    }
    if(n%5 == 0)
    {
        std::cout << n/5 << "\n";
    }
    else if(n%5 == 1)
    {
        std::cout << n/5 + 1 <<"\n";
    }
    else if(n%5 == 2)
    {
        std::cout << n/5 + 2 << "\n";
    }
    else if(n%5 == 3)
    {
        std::cout << n/5 + 1 << "\n";
    }
    else
    {
        std::cout << n/5 + 2 << "\n";
    }
    return 0;
}