#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    vector<int> a(10);
    for(int i = 1; i <= 9; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        cout << a[s[i]-'0'];
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}