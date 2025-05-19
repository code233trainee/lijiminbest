#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int mx = 1;
    for(int i = 2; i <= 16; i++)
    {
        mx = mx * i / gcd(mx, i);
    }
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> vp(17);
    vector<bool> used(17, false);
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        int k = s[i].size();
        used[k] = true;
        if (vp[k].empty()) 
        {
            vp[k].assign(k, 1);
        }
        for(int j = 0; j < k; j++)
        {
            vp[k][j] &= (int)(s[i][j]-'0');
        }
    }
    for(int i = 1; i <= 16; i++)
    {
        if(!used[i])
        {
            continue;
        }
        bool ok = false;
        for(int j = 0; j < vp[i].size(); j++)
        {
            if(vp[i][j])
            {
                ok = true;
                break;
            }
        }
        if(!ok)
        {
            cout << "-1\n";
            return 0;
        }
    }
    for(int i = 1; i <= mx; i++)
    {
        bool ok = true;
        for(int j = 1; j <= 16; j++)
        {
            if(!used[j])
            {
                continue;
            }
            int r = (i - 1) % j;
            if(vp[j][r] == 0)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}