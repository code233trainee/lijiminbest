#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--;
    y--;
    vector<string> a(h);
    for(int i = 0; i < h; i++)
    {
        cin >> a[i];
    }
    string t;
    cin >> t;
    int n = t.size();
    int i = 0;
    int cnt = 0;
    if(a[x][y] == '@')
    {
        cnt++;
        a[x][y] = '.';
    }
    while(i < n)
    {
        switch(t[i])
        {
            case 'U':
                if(x-1 > 0)
                {
                    if(a[x-1][y] == '.' || a[x-1][y] == '@')
                    {
                        x--;
                        if(a[x][y] == '@')
                        {
                            cnt++;
                            a[x][y] = '.';
                        }
                    }
                }
                break;
            case 'D':
                if(x+1 < h)
                {
                    if(a[x+1][y] == '.' || a[x+1][y] == '@')
                    {
                        x++;
                        if(a[x][y] == '@')
                        {
                            cnt++;
                            a[x][y] = '.';
                        }
                    }
                }
                break;
            case 'L':
                if(y-1 > 0)
                {
                    if(a[x][y-1] == '.' || a[x][y-1] == '@')
                    {
                        y--;
                        if(a[x][y] == '@')
                        {
                            cnt++;
                            a[x][y] = '.';
                        }
                    }
                }
                break;
            case 'R':
                if(y+1 < w)
                {
                    if(a[x][y+1] == '.' || a[x][y+1] == '@')
                    {
                        y++;
                        if(a[x][y] == '@')
                        {
                            cnt++;
                            a[x][y] = '.';
                        }
                    }
                }
                break;
        }
        i++;
    }
    cout << x+1 << " " << y+1 << " " << cnt << "\n";
    return 0;
}