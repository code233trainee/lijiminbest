#include <bits/stdc++.h>
int n, m;
int check(int i, int j, std::vector<std::string> &a)
{
    if(a[i][j] == '+')
    {
        int k = 1;
        int mx = 0;
        while(1)
        {
            if(i - k >= 0 && j - k >= 0 && i + k < n && j + k < m)
            {
                if(a[i-k][j] == '|' && a[i+k][j] == '|' && a[i][j-k] == '-' && a[i][j+k] == '-' && a[i-k][j-k] == '\\' && a[i-k][j+k] == '/' && a[i+k][j+k] == '\\' && a[i+k][j-k] == '/')
                {
                    mx++;
                    k++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return mx;
    }
    else
    {
        return 0;
    }
}
int main()
{
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int temp = check(i, j, a);
            if(temp > mx)
            {
                mx = temp;
            }
        }
    }
    std::cout << mx << "\n";
    return 0;
}