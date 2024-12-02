#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bool isok = true;
    vector<int> v1(n+1);
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            v1[v[i]] = 1;
        }
        if(i > 0)
        {
            if(v[i] == 1 || v[i] == n)
            {
                if(v[i] == 1)
                {
                    if(v1[v[i] + 1] == 1)
                    {
                        v1[v[i]] = 1;
                        continue;
                    }
                    else
                    {
                        isok = false;
                        break;
                    }
                }
                else
                {
                    if(v1[v[i] - 1] == 1)
                    {
                        v1[v[i]] = 1;
                        continue;
                    }
                    else
                    {
                        isok = false;
                        break;
                    }
                }
            }
            else
            {
                if(v1[v[i]+1] != 0 || v1[v[i]-1] != 0)
                {
                    v1[v[i]] = 1;
                    continue;
                }
                else
                {
                    isok = false;
                    break;
                }
            }
        }

    }
    
    if(isok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
}