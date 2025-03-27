#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    //n个0 m个1
    if(abs(n - m) > k || max(n, m) < k)
    {
        cout << "-1\n";
        return;
    }

    string s;
    if(n > m)
    {
        n -= k;
        for(int i = 0; i < k; i++)
        {
            s += '0';
        }
        for(int i = 0; i < min(n, m); i++)
        {
            s += "10";
        }
        if(n > m)
        {
            for(int i = 0; i < (n - m); i++)
            {
                s += '0';
            }
        }
        else
        {
            for(int i = 0; i < (m - n); i++)
            {
                s += '1';
            }
        }
    }
    else
    {
        m -= k;
        for(int i = 0; i < k; i++)
        {
            s += '1';
        }
        for(int i = 0; i < min(n, m); i++)
        {
            s += "01";
        }
        if(n > m)
        {
            for(int i = 0; i < (n - m); i++)
            {
                s += '0';
            }
        }
        else
        {
            for(int i = 0; i < (m - n); i++)
            {
                s += '1';
            }
        }
    }
    cout << s << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}