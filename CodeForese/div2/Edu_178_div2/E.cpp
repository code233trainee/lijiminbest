#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6+5;
char a[maxn];
int next_id[maxn][27], dp[maxn];
int lst[27];
void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for(int j = 0; j < k; j++)
    {
        next_id[n+1][j] = n+1;
        lst[j] = n+1; 
    }
    dp[n+1] = 0;
    for(int i = n; i >= 0; i--)
    {
        for(int j = 0; j < k; j++)
        {
            next_id[i][j] = lst[j];
            dp[i] = min(dp[i], dp[next_id[i][j]] + 1);
        }
        if(i != 0)
        {
            lst[a[i] - 'a'] = i;
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        string t;
        cin >> t;
        int id = 0;
        for(int i = 0; i < t.size(); i++)
        {
            id = next_id[id][t[i] - 'a'];
        }
        cout << dp[id] << endl;
    }
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