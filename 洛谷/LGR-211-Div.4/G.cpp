#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<string> t(m);
    for(int i = 0; i < m; i++)
    {
        cin >> t[i];
    }
    for(int i = 0; i < n; i++)
    {
        bool ok = false;
        int len2 = a[i].length();
        for(int j = 0; j < m; j++)
        {
            int len = t[j].length();
            if(len2 > len)
            {
                ok = false;
                continue;
            }
            for(int k = 0; k < len2; k++)
            {
                ok = false;
                int l = 0;
                for(l = 0; l < len && l+k < len2; l++)
                {
                    if(a[i][k+l] == t[j][l])
                    {
                        continue;
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
                if(l == len)
                {
                    ok = true;
                    break;
                }
            }
            if(ok)
            {
                break;
            }
        }
        if(ok)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}