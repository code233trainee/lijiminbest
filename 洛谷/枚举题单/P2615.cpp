#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> b(n+1, std::vector<int>(n+1));
    std::vector<std::pair<int, int>> a(n*n + 1);
    for(int i = 1; i <= n*n; i++)
    {
        //直接模拟即可
        if(i == 1)
        {
            b[1][n/2 + 1] = i;
            a[1].first = 1;
            a[1].second = n/2 + 1;
            continue;
        }
        if(a[i-1].first == 1 && a[i-1].second != n)
        {
            b[n][a[i-1].second + 1] = i;
            a[i].first = n;
            a[i].second = a[i-1].second + 1;
            continue;
        }
        if(a[i-1].second == n && a[i-1].first != 1)
        {
            b[a[i-1].first - 1][1] = i;
            a[i].first = a[i-1].first - 1;
            a[i].second = 1;
            continue;
        }
        if(a[i-1].first == 1 && a[i-1].second == n)
        {
            b[2][n] = i;
            a[i].first = 2;
            a[i].second = n;
            continue;
        }
        if(a[i-1].first != 1 && a[i-1].second != n)
        {
            if(b[a[i-1].first - 1][a[i-1].second + 1] == 0)//
            {
                b[a[i-1].first - 1][a[i-1].second + 1] = i;
                a[i].first = a[i-1].first - 1;
                a[i].second = a[i-1].second + 1;
            }
            else
            {
                b[a[i-1].first + 1][a[i-1].second] = i;
                a[i].first = a[i-1].first + 1;
                a[i].second = a[i-1].second;
            }
            continue;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
           std::cout << b[i][j] << " "; 
        }
        std::cout << "\n";
    }
    return 0;
}