#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long x, y, z, k, ans = 0;
    cin >> x >> y >> z >> k;
    for(int a = 1; a <= x; a++)
    {
        for(int b = 1; b <= y; b++)
        {
            if(k%(a*b))
            {
                continue;
            }
            long long c = k / (a*b);
            if(c > z)
            {
                continue;
            }
            ans = max(ans, ((x - a + 1) * (y - b + 1) * (z - c + 1)));
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}