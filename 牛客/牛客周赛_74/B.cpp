#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int total = max(n, m);
    if(k < total)
    {
        cout << "-1\n";
        return 0;
    }
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < min(n, m); i++)
    {
        a[i][i] = 1;
        k--;
    }
    if(n >= m)
    {
        for(int i = m; i < n; i++)
        {
            a[i][m-1] = 1;
            k--;
        }
        if(k > 0)
        {
            a[n-1][m-1] += k;
        }
    }
    else
    {
        for(int i = n; i < m; i++)
        {
            a[n-1][i] = 1;
            k--;
        }
        if(k > 0)
        {
            a[n-1][m-1] += k;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}