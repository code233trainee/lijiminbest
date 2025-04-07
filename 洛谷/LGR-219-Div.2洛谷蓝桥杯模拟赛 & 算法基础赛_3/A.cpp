#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 46*46;
    // cout << i << " ";
    // 2025 3 29
    int ans = 0;
    for(int i = 2026; i <= 46*46-1; i++)
    {
        if((i % 4 == 0 && i % 100!= 0) || (i % 400 == 0))
        {
            ans += 366;
        }
        else
        {
            ans += 365;
        }
    }
    int t = 30*4+31*5+3; 
    int total = ans + t;
    cout << total;
    return 0;
}