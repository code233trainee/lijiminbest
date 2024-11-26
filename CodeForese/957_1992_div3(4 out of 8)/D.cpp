#include <bits/stdc++.h>
using namespace std;

void solve()
{
    //贪心
    int n, m, k, cur = 0;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        cur++;
        if(s[i] == 'L')
        {
            cur = 0;
        }
        else if(cur >= m)
        {
            k--;
            if(k < 0 || s[i] == 'C')
            {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
}

void solve1()
{
    //动态规划
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}