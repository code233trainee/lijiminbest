#include <bits/stdc++.h>
using namespace std;
//主对角线:矩阵中A[ij],满足i=j

void solve()
{
    int n = 0;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> b(n*2-1);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] < 0)
            {
                int index = n + (i - j) - 1;
                if(a[i][j] < b[index])
                {
                    b[index] = a[i][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < (n * 2 - 1); i++)
    {
        ans += (b[i] * -1);
    }
    cout << ans << endl;
}

int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();    
    }
}