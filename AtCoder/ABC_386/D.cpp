#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // std::vector<std::array<int, 3>> a(m); //为什么这样会报错
    vector<vector<int>> a(m, vector<int>(3));
    for(int i = 0; i < m; i++)
    {
        int x, y;
        char c;
        cin >> x >> y >> c;
        a[i] = {x, y, c == 'W'};
    }
    sort(a.begin(), a.end());
    
    vector<int> pre(m+1, n+1);
    for(int i = 0; i < m; i++)
    {
        pre[i + 1] = pre[i];
        if(a[i][2])//白棋
        {
            pre[i + 1] = min(pre[i + 1], a[i][1]); // 选择列最靠前的
        }
    }

    vector<int> suf(m + 1);
    for(int i = m-1; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        if(a[i][2] == 0)//黑棋
        {
            suf[i] = max(suf[i], a[i][1]); // 从后面开始选择(列靠后的)
        }
    }

    for(int i = 0; i <= m; i++)
    {
        if(pre[i] <= suf[i])
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}