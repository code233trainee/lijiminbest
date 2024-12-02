#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> m;
    while(m--)
    {
        string s;
        cin >> s;
        int sn = s.length();
        if(n != sn)
        {
            cout << "NO\n";
            continue;
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
}