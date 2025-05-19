#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> start(n+2, 0);
    start[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        start[i] = start[i-1] + a[i-1];
    }
    ll total = start[n] + a[n] - 1;

    vector<ll> L(total+1, -1), R(total+1, -1);

    for(int i = 1; i < n; i++)
    {
        ll p = start[i], pend = start[i] + a[i] - 1;
        ll c = start[i+1], cend = start[i+1] + a[i+1] - 1;
        for(ll u = p; u <= pend && c <= cend; u++)
        {
            L[u] = c++;
            if(c <= cend)
            {
                R[u] = c++;
            }
        }
    }
    cout << 1 << "\n";
    for(ll u = 1; u <= total; u++)
    {
        cout << L[u] << " " << R[u] << "\n";
    }

    return 0;
}
