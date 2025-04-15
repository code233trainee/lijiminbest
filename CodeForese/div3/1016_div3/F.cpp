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
    vector<bool> c(n);
    int mx = -1;
    for(int i = 0; i < m; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            if(s == a[j])
            {
                c[j] = true;
                cnt++;
            }
        }
        mx = max(mx, cnt);
    }
    for(int i = 0; i < n; i++)
    {
        if(!c[i])
        {
            cout << "-1\n";
            return;
        }
    }
    cout << 3*n - 2*mx << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}