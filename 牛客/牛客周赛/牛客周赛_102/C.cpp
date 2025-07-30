#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    string A, B;
    for(int i = 0; i < n; i++)
    {
        if(i%2)
        {
            A += '1';
            B += '0';
        }
        else
        {
            A += '0';
            B += '1';
        }
    }
    int ans = 0;
    auto work = [&](string t, string k) -> int {
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            if(t[i] != k[i])
            {
                if(i == n - 1)
                {
                    res = 1e9;
                    break;
                }
                else
                {
                    if(t[i] != k[i])
                    {
                        t[i] ^= 1;
                        t[i+1] ^ 1;
                        res++;
                    }
                }
            }
        }
        return res;
    };
    ans = min(work(s, A), work(s, B));
    if(ans > 1e8)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}