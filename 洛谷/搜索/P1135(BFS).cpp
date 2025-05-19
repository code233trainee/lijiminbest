#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 210;
int a[N];
int dis[N];
vector<vector<int>> g(N);
int main()
{
    int n, A, B;
    cin >> n >> A >> B;
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
    if(A == B)
    {
        cout << 0 << endl;
        return 0;
    }
    queue<int> q;
    q.push(A);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i]; 
            if(dis[v])
            {
                continue;
            }
            dis[v] = dis[u]+1;
            q.push(v);
        }
    }
    if(dis[B])
    {
        cout << dis[B] << endl;
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}