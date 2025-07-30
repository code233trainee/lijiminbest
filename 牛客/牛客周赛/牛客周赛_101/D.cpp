#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int k = m;
    int cnt = 0;
    vector<int> stru;
    while(k)
    {
        if(k & 1)
        {
            stru.push_back(cnt);
        }
        k >>= 1;
        cnt++;
    }
    if(n < (1 << (--cnt)) || ((m & 1) != 1))
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    vector<bool> vis(n+1, false);
    for(int i = 0; i < stru.size(); i++)
    {
        if(stru[i] == 0)
        {
            continue;
        }
        ans.push_back(1 << stru[i]);
        vis[(1 << stru[i])] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            ans.push_back(i);
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << stru.size() << "\n";
    for(int i = 1; i <= stru.size()-1; i++)
    {
        cout << i << " " << i << endl;
    }
    cout << stru.size() << " " << n << endl;
    return 0;
}