#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    vector<ll> a(4);
    for(int i = 1; i <= 3; i++)
    {
        cin >> a[i];
    }
    ll x;
    cin >> x;
    ll num = a[x];
    sort(a.begin()+1, a.end());
    if(num != a[3])
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
    return 0;
}