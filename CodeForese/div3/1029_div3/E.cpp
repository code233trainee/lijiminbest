#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int res = -1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == b[i])
        {
            res = i;
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(a[i] == a[i+1] || b[i] == b[i+1])
        {
            res = max(res, i);
        }
    }
    set<int> s;
    for(int i = n - 1; i >= 1; i--)
    {
        //隔一个格子，形如: 1 2 3 4
        //                 ^   ^
        if(s.count(a[i-1]) || s.count(b[i-1]))
        {
            res = max(res, i-1);
        }
        s.insert(a[i]);
        s.insert(b[i]);
    }
    cout << res + 1 << endl;

}
int main(){
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
