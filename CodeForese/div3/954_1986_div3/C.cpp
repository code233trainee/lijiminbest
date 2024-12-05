#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s, c;
    cin >> s;
    vector<int> v(m+1);
    for(int i = 1; i <= m; i++)
    {
        cin >> v[i];
    }
    cin >> c;
    sort(c.begin(), c.end());
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        //不能重复，如果重复了就有可能把字典序改小
        if(v[i] != v[i-1])
        {
            s[v[i]-1]=c[cnt++];
        }
    }
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
}