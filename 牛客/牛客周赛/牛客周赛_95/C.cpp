#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) 
{
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    ll d, p;
    cin >> d >> p;
    ll g = gcd(d, p);
    ll T = p / g;
    
    int q;
    cin >> q;
    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        if(p == 1)
        {
            if(l == 1 && r > 1)
            {
                cout << "2\n";
            }
            else
            {
                cout << "1\n";
            }
        }
        else
        {
            cout << min(r - l + 1, T) << "\n";
        }
    }
    return 0;
}