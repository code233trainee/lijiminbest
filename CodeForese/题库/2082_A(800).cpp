#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int r = 0, c = 0;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < m; j++)
        {
            sum ^= (a[i][j] - '0');
        }
        if(sum)
        {
            r++;
        }
    }
    for(int j = 0; j < m; j++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum ^= (a[i][j] - '0');
        }
        if(sum)
        {
            c++;
        }
    }
    cout << max(r, c) << "\n";
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