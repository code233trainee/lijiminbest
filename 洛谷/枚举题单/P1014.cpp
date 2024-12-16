#include <bits/stdc++.h>
#define ll long long
int main()
{
    ll n;
    std::cin >> n;
    int i = 1;
    while(1)
    {
        if(n > i)
        {
            n -= i;
            i++;
            continue;
        }
        else
        {
            if(i&1)
            {
                std::cout << i-n+1 << '/' << n << "\n";
            }
            else
            {
                std::cout << n << '/' << i-n+1 << "\n";
            }
            return 0;
        }
    }
    return 0;
}