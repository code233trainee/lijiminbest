#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> v[100010];
int odd[100010],even[100010];
void bfs()
{
    memset(odd, 0x3f, sizeof(odd));
    memset(even, 0x3f, sizeof(even));
    queue<pair<int, int>> q;
    for(int i = 0; i < v[1].size(); i++)
    {
        odd[v[1][i]] = 1;
        q.push(make_pair(v[1][i], 1));
    }
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < v[x].size(); i++)
        {
            if(y % 2 == 1)
            {
                if(y+1 < even[v[x][i]])
                {
                    even[v[x][i]] = y+1;
                    q.push(make_pair(v[x][i], y + 1));
                }
            }
            else
            {
                if(y + 1 < odd[v[x][i]])
                {
                    odd[v[x][i]] = y+1;
                    q.push(make_pair(v[x][i], y + 1));
                }
            }
        }
    }
}
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs();
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        if(y % 2 == 0)
        {
            if(even[x] > y)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
        else
        {
            if(odd[x] > y)
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}