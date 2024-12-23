#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> r(n+1), d(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> r[i];
        d[r[i]]++;
    }
    set<pair<int, int>> s;
    for(int i = 1; i <= n; i++)
    {
        s.insert({d[i], i});
    }
    int ans = 2;
    queue<int> q;
    while(!s.empty() && (*s.begin()).first == 0)
    {
        while(!s.empty() && (*s.begin()).first == 0)
        {
            int k = (*s.begin()).second;
            auto it = s.find({d[r[k]], r[k]});
            d[r[k]]--;
            if(it != s.end())
            {
                s.erase(it);
                q.push(r[k]);
            }
            s.erase(s.begin());
        }
        while(!q.empty())
        {
            s.insert({d[q.front()], q.front()});
            q.pop();
        }
        ans++;
    }
    cout << ans << "\n";
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