#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    vector<int> num1(n);
    vector<int> num1c(m);
    int cnt1 = 0; 
    for(int i = 0; i < n; i++)
    {
        int t = 0;
        cin >> vs[i];
        for(int j = 0; j < m; j++)
        {
            if(vs[i][j] == '1')
            {
                t++;
                cnt1++;
            }
        }
        num1[i] = t;
    }
    for(int i = 0; i < m; i++)
    {
        int t = 0;
        for(int j = 0; j < n; j++)
        {
            if(vs[j][i] == '1')
            {
                t++;
            }
        }
        num1c[i] = t;
    }
    if(num1[0] == 0 || num1[n-1] == 0 || num1c[0] == 0 || num1c[m-1] == 0)
    {
        cout << "-1\n";
        return;
    }
    if(cnt1 == n*m)
    {
        cout << "0\n";
        return;
    }
    bool l1 = false, r1 = false, l2 = false, r2 = false;
    if(vs[0][0] == '1') l1 = true;
    if(vs[0][m-1] == '1') r1 = true;
    if(vs[n-1][0] == '1') l2 = true;
    if(vs[n-1][m-1] == '1') r2 = true;
    int k = (l1 + l2 + r1 + r2);
    if((l1 && r2) || (l2 && r1))
    {
        cout << "1\n";
        return;
    }
    if(k >= 1)
    {
        cout << "2\n";
    }
    else
    {
        cout << "3\n";
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