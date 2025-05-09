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
    vector<int> row(n), column(m);
    int cnt1 = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '1')
            {
                cnt1++;
                row[i]++;
                column[j]++;
            }
        }
    }
    int Cr = 0;
    for(int i = 0; i < n; i++)
    {
        Cr += (row[i] == m);
    }
    int Cc = 0;
    for(int i = 0; i < m; i++)
    {
        Cc += (column[i] == n);
    }

    bool ok = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '0')
            {
                if(row[i] == m-1 && column[j] == n-1 && cnt1 == m + n - 2)
                {
                    ok = true;
                    break;
                }
            }
        }
        if(ok)
        {
            break;
        }
    }

    if(cnt1 == 0 || (Cr == 2 && cnt1 == m*2) || (Cc == 2 && cnt1 == n*2) || ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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