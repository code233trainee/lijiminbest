#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(26);
    for(int i = 0; i < n; i++)
    {
        a[s[i]-'a']++;
    }
    vector<int> ans;
    for(int i = 0; i < 26; i++)
    {
        if(a[i] != 0)
        {
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 1; i < ans.size(); i++)
    {
        if(ans[i] != ans[i-1] + 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}