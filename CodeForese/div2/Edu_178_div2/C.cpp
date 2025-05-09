#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;
    if(s[1] == s[n] && s[n] == 'A')
    {
        cout << "Alice\n";
        return;
    }
    else if(s[1] == s[n] && s[n] == 'B')
    {
        cout << "Bob\n";
        return;
    }
    int cntA = 0, cntB = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == 'A')
        {
            cntA++;
        }
        else
        {
            cntB++;
        }
    }
    // A....B
    if(s[1] == 'A')
    {
        if(cntB == 1)
        {
            cout << "Alice\n";
            return;
        }
        else
        {
            cout << "Bob\n";
            return;
        }
    }
    else // B....A
    {
        if(cntA == 1)
        {
            cout << "Bob\n";
        }
        else
        {
            if(s[n-1] == 'A')
            {
                cout << "Alice\n";
                return;
            }
            else
            {
                cout << "Bob\n";
                return;
            }
        }
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