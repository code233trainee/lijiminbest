#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int n, g;
    cin >> n >> g;
    ll ans = -n;
    int lst = 0;
    for(int l = 0, r = 1; r <= n; r++)
    {
        int a;
        cin >> a;
        if(gcd(a, g) != g)
        {
            l = lst;
            lst = r;
        }
        ans += 1ll * (r - l);
    }
    cout << ans << endl;
    return 0;
}