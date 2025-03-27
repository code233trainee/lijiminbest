#include  <bits/stdc++.h>
using namespace std;
int main()
{
    //简单图不含自环和重边
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> e;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(u == v)
        {
            continue;
        }
        if(u > v)
        {
            swap(u, v);
        }
        e.insert({u, v});
    }
    cout << m - e.size() << "\n";
    return 0;
}