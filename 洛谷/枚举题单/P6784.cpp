#include <bits/stdc++.h>
int main()
{
    long long a, b, c;
    std::cin >> a >> b >> c;
    if((a == 0 || b == 0))
    {
        std::cout << "0";
        return 0;
    }
    if(a < b)
    {
        if(b - a > c)
        {
            a += c;
            c = 0;
        }
        else
        {
            c -= b - a;
            a = b;
        }
    }
    if(a > b)
    {
        if(a-b > c)
        {
            b += c;
            c = 0;
        }
        else
        {
            c -= a - b;
            b = a;
        }
    }
    a += c/2;
    b += c/2;
    for(long long i = 1; i <= std::min(a, b); i++)
    {
        a -= i;
        b -= i;
        if(a < i || b < i)
        {
            std::cout << i;
            return 0;
        }
    }
    return 0;
}