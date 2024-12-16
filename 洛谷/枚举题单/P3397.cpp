#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n+1, std::vector<int>(n+1));
    while(m--)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                a[i][j]++;
            }
        }
    } 
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}