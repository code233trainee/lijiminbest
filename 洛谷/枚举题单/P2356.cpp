#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool ok = false;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> x, y;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0)
            {
                x.push_back(j);
                y.push_back(i);
                ok = true;
            }
        }
    }
    int ans = 0;
    if(ok)
    {
        vector<int> hang(n);
        vector<int> lie(n);
        //注意数组数据的处理
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                hang[i] += a[i][j];
            }
        }
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < n; i++)
            {
                lie[j] += a[i][j];
            }
        }
        for(int i = 0; i < x.size(); i++)
        {
            ans = max(ans, hang[y[i]] + lie[x[i]]);
        }
        cout << ans << endl;
    }
    else
    {
        cout << "Bad Game!" << endl;
    }
    
    return 0;
}