#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    while(n >= c || n >= b || n >= a)
    {
        if(n >= a)
        {
            n -= a;
            ans++;
            continue;
        }
        if(n >= b)
        {
            n -= b;
            ans++;
            continue;
        }
        if(n >= c)
        {
            n -= c;
            ans++;
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}