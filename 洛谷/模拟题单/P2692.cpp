#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, b, g;
    cin >> n >> m >> b >> g;
    vector<bool> row(n+1);
    vector<bool> column(m+1);
    while(b--)
    {
        int c, d;
        cin >> c >> d;
        for(int i = c; i <= d; i++)
        {
            row[i] = true;
        }
    }
    while(g--)
    {
        int e, f;
        cin >> e >> f;
        for(int i = e; i <= f; i++)
        {
            column[i] = true;
        }
    }
    int hang = 0, lie = 0;
    for(int i = 1; i <= n; i++)
    {
        if(row[i])
        {
            hang++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(column[i])
        {
            lie++;
        }
    }
    cout << hang*m + lie*n - lie*hang << "\n";
    return 0;
}