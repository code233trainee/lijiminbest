#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int big = 0;
    int small = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != b[i])
        {
            if(a[i] > b[i])
            {
                big += a[i] - b[i];
            }
            if(a[i] < b[i])
            {
                small += b[i] - a[i];
            }
        }
    }
    cout << big + 1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}