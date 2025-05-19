#include<bits/stdc++.h> 
using namespace std;
int main( )
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n+1), dst(n+1);
    vector<vector<int>> g(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i - a[i] >= 1)
        {
            g[i].push_back(i - a[i]);
        }
        if(i + a[i] <= n)
        {
            g[i].push_back(i + a[i]);
        }
    }
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i];
            //已经到达了的肯定比再次到达的所需步数小
            //所以这里直接跳过
            if(dst[v])
            {
                continue;
            }
            dst[v] = dst[u]+1;
            q.push(v);
        }
    }
    if(dst[y])
    {
        cout << dst[y];
    }
    else
    {
        cout << -1;
    }
    return 0;
}