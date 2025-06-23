#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
int a[N][N][N];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < m; k++)
            {
                cin >> a[i][j][k];
            }
        }
    }

    
    for(int i = n - 2; i >= 0; i--)
    {
        auto b = a[i];
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < m; k++)
            {
                for(int p = 0; p < m; p++)
                {
                    int sum = 0;
                    for(int v = 0; v < m; v++)
                    {
                        sum += (b[v][p] * a[i])
                    }
                    a[n-1][j][k] =     
                }
            }
        }
    }
    for(int j = 0; j < m; j++)
    {
        for(int k = 0; k < m; k++)
        {
            cout << a[n-1][j][k] << " ";
        }
        cout << endl;
    }
    return 0;
}