#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n, vis[N], ans;
string s[N];
char c;
void dfs(const string &tmp)
{
    ans = max(ans, (int)(tmp.size()));
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] >= 2)
        {
            continue;
        }
        for(int j = 1; j < min(tmp.size(), s[i].size()); j++)
        {
            if(tmp.substr(tmp.size() - j) == s[i].substr(0, j))
            {
                vis[i]++;
                dfs(tmp + s[i].substr(j));
                vis[i]--;
            }
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    cin >> c;
    for(int i = 1; i <= n; i++)
    {
        if(s[i][0] == c)
        {
            vis[i]++;
            dfs(s[i]);
            vis[i]--;
        }
    }
    cout << ans << "\n";
    return 0;
}