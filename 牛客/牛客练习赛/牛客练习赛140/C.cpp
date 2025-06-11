#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    set<int> s;
    int sz = s.size();
    for(int i = 1; i <= n; i++)
    {
        s.insert(a[i]);
        if(a[i] && sz == s.size())
        {
            cout << -1 << "\n";
            return;
        }
        sz = s.size();
    }

    int mx = *(max_element(s.begin(), s.end()));
    if(mx > sz)
    {
        cout << -1 << "\n";
        return;
    }

    int lacki = -1;
    if(mx == sz)
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == mx)
            {
                lacki = i;
                break;
            }
        }
    }

    vector<int> o(n+1);
    if(lacki != -1) {
        vector<int> b = a;
        sort(b.begin() + 1, b.end());

        b[0] = -1;

        int lacknum = -1;
        for(int i = 1; i <= n; i++)
        {
            if(b[i] == b[i-1] + 2)
            {
                lacknum = b[i-1] + 1;
            }
        }    

        for(int i = 1; i <= n; i++)
        {
            o[a[i]] = i;
        }

        o[lacknum] = lacki;

        cout << mx << "\n";
        for(int i = 1; i <= mx; i++)
        {
            cout << o[i] << " \n"[i == mx];
        }
    } else {
        for(int i = 1; i <= n; i++)
        {
            o[a[i]] = i;
        }

        cout << mx << "\n";
        for(int i = 1; i <= mx; i++)
        {
            cout << o[i] << " \n"[i == mx];
        }
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