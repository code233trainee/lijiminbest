#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    int n;
    cin >> n >> s;
    set<int> se;
    for(int i = 1; i < n; i++)
    {
        if(se.count(s[i] - 'a'))
        {
            cout << "Yes\n";
            return;
        }
        se.insert(s[i] - 'a');
    }
    se.clear();
    for(int i = n-2; i >= 0; i--)
    {
        if(se.count(s[i] - 'a'))
        {
            cout << "Yes\n";
            return;
        }
        se.insert(s[i] - 'a');
    }
    cout << "No\n";
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
