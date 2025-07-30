#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string l, r;
    cin >> l >> r;
    int n = l.size();
    int res = 0;
    if(l == r)
    {
        cout << n * 2 << endl;
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(l[i] == r[i])
        {
            res += 2;
        }
        else if(r[i] - l[i] > 1)
        {
            cout << res << endl;
            return;
        }
        else
        {
            res++;
            for(int j = i+1; j < n; j++)
            {
                if(l[j] == '9' && r[j] == '0')
                {
                    res++;
                }
                else
                {
                    cout << res << endl;
                    return;
                }
            }
            break;
        }
    }
    cout << res << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}