#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int l = 0, r = n-1;
    while(l <= r)
    {
        if(s[l] < s[r])
        {
            cout << "YES\n";
            return;
        }
        else if(s[l] > s[r])
        {
            if(k > 0)
            {
                cout << "YES\n";
                return;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            l++;
            r--;
        }
    }
    bool check = false;
    for(int i = 0; i < n; i++)
    {
        if(s[0] != s[i])
        {
            check = true;
        }
    }
    if(check)
    {
        cout << (k > 0 ? "YES" : "NO") << "\n";
    }
    else
    {
        cout << "NO\n";
    }
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