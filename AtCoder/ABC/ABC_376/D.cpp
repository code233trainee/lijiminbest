#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    vector<int> dis(N, -1);
    queue<int> q;
    dis[0] = 0;
    q.push(0);

    int ans = N + 1;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(auto y : adj[x])
        {
            if(y == 0)
            {
                ans = min(ans, dis[x] + 1);
            }
            if(dis[y] == -1)
            {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    if(ans > N)
    {
        ans = -1;
    }
    cout << ans << "\n";
    
    return 0;
}