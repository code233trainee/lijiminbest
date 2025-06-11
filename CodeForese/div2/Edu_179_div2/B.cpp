#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    for(int i = 2; i < n; i++)
    {
        fib.push_back(fib[i-1] + fib[i-2]);
    }
    n--;
    while(m--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        vector<ll> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        if(v[1] < fib[n] || v[2] < fib[n] || v[0] < fib[n])
        {
            cout << "0";
            continue;
        }
        if(v[2] >= fib[n] + fib[n-1])
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
    cout << "\n";
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