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
void solve()
{
    int p, s;
    cin >> p >> s;
    int g = gcd(p, s);
    p /= g;
    s /= g;
    if(2 * s >= p)
    {
        //case 1: 2*s*(a+b)/p = a+b...a*b
        int s2 = s * 2, p2 = p;
        if(p % 2 == 0)
        {
            s2 /= 2;
            p2 /= 2;
        }
        int a = 200;
        int b = a / p2 * p2 - a % p2;
        int tot = s2 * (a + b) / p2;
        cout << tot << "\n";
        for(int i = 1; i <= a; i++)
        {
            cout << i << " " << 1 << "\n";
        }
        for(int i = 2; i <= b; i++)
        {
            cout << 1 << " " << i << "\n";
        }
        int x = 2, y = 2;
        for(int i = a + b - 1; i < tot; i++)
        {
            cout << x << " " << y << "\n";
            if(y + 1 <= b) {
                y++;
            } else {
                x++;
                y = 2;
            }
        }
        return;
    }
    // case 2: 2*s*(a+b)/p = a+b-1
    int c1 = 2*s, c2 = p - 2 * s;
    if(c1 % c2 == 0)
    {
        int a = c1 / c2;
        cout << a << "\n";
        for(int i = 1; i <= a; i++)
        {
            cout << 1 << " " << i << "\n";
        }
        return;
    }
    cout << -1 << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}