#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    
    //题目要求的是完全匹配
    int n, m;
    cin >> n >> m;
    vector<string> s(n+1);
    vector<string> t(m+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> t[i];
        t[i] = ' ' + t[i];
    }
    int a = 1, b = 1;
    for(a = 1; a <= n - m + 1; a++)
    {
        for(b = 1; b <= n - m + 1; b++)
        {
            bool ok = true;
            for(int x = 1; x <= m; x++)
            {
                for(int y = 1; y <= m; y++)
                {
                    ok &= (s[a+x-1][b+y-1] == t[x][y]);
                    
                }
            }
            if(ok)
            {
                cout << a << " " << b << "\n";
                return 0;
            }
        }
    }
    return 0;
}