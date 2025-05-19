#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    bool sing = true;
    int cnt = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        if(s[i] != s[0])
        {
            break;
        }
    }
    if(i >= n)
    {
        cout << "1\n";
    }
    else
    {
        for(j = i + 1; j < n; j++)
        {
            if(s[j] != s[i])
            {
                cout << "2\n";
                return;
            }
        }
        cnt = count(s.begin(), s.end(), s[i]);
        cout << 1+min(3, cnt) << "\n";
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