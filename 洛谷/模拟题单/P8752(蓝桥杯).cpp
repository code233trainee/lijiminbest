#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int ans = 0;
    while(n--)
    {
        int year;
        cin >> year;
        int a, b, c, d;
        d = year % 10;
        year /= 10;
        c = year % 10;
        year /= 10;
        b = year % 10;
        year /= 10;
        a = year;
        if(a == c && d == b+1)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}