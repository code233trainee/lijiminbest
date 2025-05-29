#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 305;
int a[N][N], suff[N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        suff[i] = 0;
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = n; j >= 1; j--)
        {
            if(a[i][j] != 1)
            {
                break;
            }
            suff[i]++;
        }
    }

    multiset<int> s;
    for(int i = 1; i <= n; i++)
    {
        s.insert(suff[i]);
    }
    int ans = 1;
    while(!s.empty())
    {
        int cur = *s.begin();
        if(cur >= ans)
        {
            ans++;
        }
        s.extract(cur);
    }
    cout << min(ans, n) << "\n";
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