#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll t;
    cin >> t;
    ll mi = INT64_MAX;
    ll sum = 0;
    ll total = 0;
    while(t--)
    {
        ll k;
        cin >> k;
        sum += k;
        vector<int> b, c;
        for(int i = 1; i <= k; i++)
        {
            ll a;
            cin >> a;
            total += a;
            b.push_back(a);
            if(a < mi)
            {
                mi = a;
            }
        }
        c = b;
        sort(b.begin(), b.end());
        if(b != c)
        {
            cout << "NO" << "\n";
            return 0;
        }
    }
    sum = sum + mi - 1;
    ll a = sum*(sum+1)/2;
    ll b = (mi-1)*mi/2;
    cout << ((a-b) == total ? "YES" : "NO") << "\n";
    return 0;
}