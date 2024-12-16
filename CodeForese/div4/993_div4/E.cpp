#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll count = 0;
    for (long long x = l1; x <= r1; ++x) {
        long long y = x;
        while (y <= r2) {
            if (y >= l2) count++;
            if (y > r2 / k) break;
            y *= k;
        }
    }
    cout << count << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}