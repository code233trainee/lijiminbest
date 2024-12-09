#include <bits/stdc++.h>
using namespace std;
//最多为n*(n-1),n<=20
int a[25][25];
int main()
{
    int n, k, ans = 0;
    cin >> k >> n;
    vector<int> b;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int m;
            cin >> m;
            for(int l = 0; l < b.size(); l++)
            {
                a[b[l]][m]++;
            }
            b.push_back(m);
        }
        b.clear();
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == k)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}