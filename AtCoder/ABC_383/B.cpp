#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w, d;
    cin >> n >> w >> d;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<bool>> b(n, vector<bool>(w));
    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(a[i][j] == '.')
            {
                for(int x = 0; x < n; x++)
                {
                    for(int y = 0; y < w; y++)
                    {
                        if(a[x][y] == '.')
                        {
                            int cur = 0;
                            for(int k = 0; k < n; k++)
                            {
                                for(int g = 0; g < w; g++)
                                {
                                    if(a[k][g] == '.')
                                    {
                                        if(abs(k-i) + abs(g-j) <= d || abs(k-x) + abs(g-y) <= d)
                                        {
                                            cur++;
                                        }
                                    }
                                }
                            }
                            ans = max(ans, cur);
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}