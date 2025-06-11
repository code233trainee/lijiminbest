#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll q;
    cin >> q;
    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        if(r - l <= 1 && l != 1)
        {
            cout << "-1\n";
        }
        else
        {
            ll k = r - l + 1;
            if(k % 2 == 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << 1 << "\n";
            }
        }
    }
    return 0;
}