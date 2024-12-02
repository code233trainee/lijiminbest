#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m;
    cin >> n >> m;
    vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int> dy = {1, -1, 2, -2, 2, -2, 1, -1};
    vector<pair<int, int>> p;
    for(int i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;
        a--;
        b--;
        for(int j = 0; j < 8; j++)
        {
            int s = a + dx[j];
            int t = b + dy[j];
            if(min(s, t) < 0 || n <= max(s, t))
            {
                continue;
            }
            p.push_back({s, t});
        }
        p.push_back({a, b});
    }
    sort(p.begin(), p.end());
    p.push_back({-1, -1});
    long long ans = n*n;
    for(int i = 1; i < p.size(); i++)
    {
        if(p[i] != p[i-1])
        {
            ans--;
        }
    }
    cout << ans << "\n";
}