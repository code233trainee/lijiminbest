#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        int mn = INT_MAX;
        for(int j = i; j < n; j++)
        {
            if(a[j] < mn)
            {
                mn = a[j];
                sum += mn;
            }
            else
            {
                sum += mn;
            }
        }
    }
    cout << sum << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}