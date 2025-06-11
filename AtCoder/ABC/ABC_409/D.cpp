#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = 0;
    bool ok = false;
    for(l = 0; l < n-1; l++)
    {
        if(s[l+1] < s[l])
        {
            ok = true;
            break;
        }
    }
    if(!ok)
    {
        cout << s << "\n";
        return;
    }
    bool ok2 = false;
    for(r = l+1; r < n-1; r++)
    {
        if(s[r+1] > s[l])
        {
            ok2 = true;
            break;
        }
    }
    if(!ok2)
    {
        r = n-1;
    }
    char c = s[l];
    for(int i = l; i <= r-1; i++)
    {
        s[i] = s[i+1];
    }
    s[r] = c;
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