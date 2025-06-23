#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    set<int> pos;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            pos.insert(i);
        }
    }
    int last = -1;
    int tot = 1;
    if(!pos.empty())
    {
        for(auto &z : pos)
        {
            if(last == -1)
            {
                last = z;
            }
            else
            {
                if(z - last > 1)
                {
                    tot++;
                    last = z;
                }
                else
                {
                    last = z;
                }
            }
        }
        if(s[n-1] == '1')
        {
            if(tot == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << tot*2-1<<endl;
            }
        }
        else
        {
            cout << tot*2 << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }
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