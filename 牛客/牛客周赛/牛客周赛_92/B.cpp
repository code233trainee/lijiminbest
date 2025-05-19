#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    int x, y;
    for(int i = 0; i < n; i++)
    {
        bool ok = false;
        for(int j = 0; j < m; j++)
        {
            if(vs[i][j] == '#')
            {
                x = i;
                y = j;
                ok = true;
                break;
            }
        }
        if(ok)
        {
            break;
        }
    }
    string ans = "";
    if(x == 0)
    {
        ans += "S";
        ans.append(m-1, 'D');
        ans.append(n-2, 'S');
    }
    else if(y == m-1)
    {
        ans.append(m-2, 'D');
        ans.append(n-1, 'S');
        ans += 'D';
    }
    else
    {
        ans.append(m-1, 'D');
        ans.append(n-1, 'S');
    }
    cout << ans << endl;
    return 0;
}