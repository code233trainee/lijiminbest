#include <bits/stdc++.h>
using namespace std;
int x = 0, y = 0;
vector<vector<int>> ans;
void work(int i1, int j1, int i2, int j2, vector<string> &s)
{
    swap(s[i1][j1], s[i2][j2]);
    ans.push_back({i1+1, j1+1, i2+1, j2+1});
}
void movex(int i, int j, int x, int y, vector<string> &s)
{
    while(i < x)
    {
        work(i, j, i + 1, j, s);
        i++;
    }
    while(i > x)
    {
        work(i, j, i - 1, j, s);
        i--;
    }
}
void movey(int i, int j, int x, int y, vector<string> &s)
{
    while(j < y)
    {
        work(i, j, i, j + 1, s);
        j++;
    }
    while(j > y)
    {
        work(i, j, i, j - 1, s);
        j--;
    }
}
void move(int i, int j, int x, int y, vector<string> &s)
{
    if(i >= x)
    {
        movey(i, j, x, y, s);
        movex(i, j, x, y, s);
    }
    else
    {
        movex(i, j, x, y, s);
        movey(i, j, x, y, s);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    x = 0, y = 0;
    ans.clear();
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            while(s[i][j] == '1')
            {
                move(i, j, x, y, s);
                s[x][y] = '2';
                y++;
                if(y == n/2)
                {
                    x++;
                    y = 0;
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
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}