#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> d(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    vector<int> l(n+1), r(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    vector<int> L(n+1), R(n+1);
    L[0] = R[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] != -1)
        {
            L[i] = L[i-1] + d[i];
            R[i] = R[i-1] + d[i];
        }
        else
        {
            R[i] = R[i-1] + 1;
            L[i] = L[i-1];
        }
        L[i] = max(L[i], l[i]);
        R[i] = min(R[i], r[i]);
        if(L[i] > R[i])
        {
            cout << -1 << "\n";
            return;
        }
    }
    vector<int> h(n+1);
    h[n] = L[n];
    for(int i = n; i >= 1; i--)
    {
        if(d[i] != -1)
        {
            h[i-1] = h[i] - d[i];
        }
        else
        {
            if(L[i-1] <= h[i] && h[i] <= R[i-1])
            {
                h[i-1] = h[i];
                d[i] = 0;
            }
            else
            {
                h[i-1] = h[i] - 1;
                d[i] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " \n"[i == n];
    }
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