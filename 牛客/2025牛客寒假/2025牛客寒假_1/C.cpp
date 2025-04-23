#include <bits/stdc++.h>
using namespace std;

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> ans;
    auto work = [&](int i1, int j1, int i2, int j2)
    {
        swap(a[i1][j1], a[i2][j2]);
        ans.push_back({i1+1, j1+1, i2+1, j2+1});
    };

    auto move = [&](int i, int j, int x, int y) {
        auto movex = [&]() {
            while(i < x)
            {
                work(i, j, i+1, j);
                i++;
            }
            while(i > x) 
            {
                work(i, j, i - 1, j);
                i--;
            }
        };
        auto movey = [&]() {
            while(j < y)
            {
                work(i, j, i, j+1);
                j++;    
            }
            while(j > y)
            {
                work(i, j, i, j - 1);
                j--;
            }
        };
        if(i >= x)
        {
            movey();
            movex();
        }
        else
        {
            movex();
            movey();
        }
    };
    int x = 0, y = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            while(a[i][j] == '1')
            {
                move(i, j, x, y);
                a[x][y] = '2';
                y++;
                if(y == n / 2)
                {
                    y = 0;
                    x++;
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}