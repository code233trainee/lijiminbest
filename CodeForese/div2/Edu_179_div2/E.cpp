#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector c(23, set<int>());
    // vector<set<int>> d(23);
    for(int i = 0; i < m; i++)
    {
        char c1, c2;
        cin >> c1 >> c2;
        int k = (c1-'a')*10 + (c2-'a');
        c[k].insert(i);
    }
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'a') continue;
        if(s[i] == 'b') {
            if(!c[10].empty()) {
                s[i] = 'a';
                c[10].erase(c[10].begin());
            } else {
                if(!c[12].empty() && !c[20].empty())
                {
                    //位置大于，因为b->c,c->a,第二个操作只能在第一个操作之后
                    auto it = c[20].upper_bound(*c[12].begin());
                    if(it != c[20].end())
                    {
                        s[i] = 'a';
                        c[12].erase(c[12].begin());
                        c[20].erase(it);
                    }
                }
            }
        } else {//为c
            if(!c[20].empty()) {
                s[i] = 'a';
                c[20].erase(c[20].begin());
            } else {
                if(!c[21].empty() && !c[10].empty()) {
                    auto it = c[10].upper_bound(*c[21].begin());
                    if(it != c[10].end())
                    {
                        s[i] = 'a';
                        c[21].erase(c[21].begin());
                        c[10].erase(it);
                    }
                    else
                    {
                        s[i] = 'b';
                        c[21].erase(c[21].begin());
                    }
                } else if(!c[21].empty()){
                    s[i] = 'b';
                    c[21].erase(c[21].begin());
                }
            }
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
    return 0;
}