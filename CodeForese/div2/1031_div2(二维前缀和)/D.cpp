#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(array<int, 2> a, array<int, 2> b)
{
    return a[0] > b[0];
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<array<int, 2>> c(n);
    for(int i = 0; i < n; i++)
    {
        c[i] = {b[i], i};
    }
    sort(c.begin(), c.end(), cmp);
    set<int> l;
    set<int> r(a.begin(), a.end());
    int res = 0;
    int ai = 0;
    for(auto &t : c)
    {
        while(ai < n)
        {
            l.insert(a[ai]);
            r.erase(a[ai]);
            ai++;
            if(*l.begin() > t[0]){
                continue;
            } else if(!r.empty() && *r.rbegin() > t[0] && 
                    (l.size() == 1 || *next(l.begin()) > t[0])) {
                continue;
            } else {
                ai--;
                l.erase(a[ai]);
                r.insert(a[ai]);
                break;
            }
        }
        res = max(res, min(ai, n - t[1]));
    }
    cout << res << endl;
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