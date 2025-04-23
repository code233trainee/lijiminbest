#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    ll Aeven = 0;
    ll Beven = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if((a[i]&1))
        {
            Aeven++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        if(b[i]&1)
        {
            Beven++;
        }
    }
    if(Aeven == n-Beven)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}