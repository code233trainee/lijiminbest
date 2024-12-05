#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c;
    for(int i = 0; i < n; i++)
    {
        c.push_back(s[i] - 'a');
    }
    sort(c.begin(), c.end());
    //去除重复元素并且重新设置大小，这样设置之后的数字就只有不重复的元素了
    c.resize(unique(c.begin(), c.end()) - c.begin());
    int j = c.size();
    vector<int> cd(26);
    int l = 0, r = j - 1;
    while(l == r || l < r)
    {
        cd[c[l]] = c[r];
        cd[c[r]] = c[l];
        r--;
        l++;
    }
    for(auto &z : s)
    {
        z = cd[z - 'a'] + 'a'; 
    }
    cout << s << endl;
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