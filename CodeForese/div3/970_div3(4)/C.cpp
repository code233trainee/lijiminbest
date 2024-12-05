#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int l, r;
    cin >> l >> r;
    if(l == r)
    {
        cout << 1 << endl;
        return;
    }
    int cnt = 0;
    int sub = 0;
    vector<int> v;
    while(l <= r)
    {
        v.push_back(l);
        l += sub + 1;
        sub++;
    }
    cout << v.size() << endl;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
}