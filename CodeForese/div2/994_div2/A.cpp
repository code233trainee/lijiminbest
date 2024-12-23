#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while(!a.empty() && a.back() == 0)
    {
        a.pop_back();
    }
    //数组顺序颠倒
    reverse(a.begin(), a.end());
    while(!a.empty() && a.back() == 0)
    {
        a.pop_back();
    }
    reverse(a.begin(), a.end());
    if(a.empty())
    {
        cout << "0\n";
        return;
    }
    bool has0 = false;
    for(auto &z : a)
    {
        has0 |= (z == 0);
    }
    if(has0)
    {
        cout << "2\n";
    }
    else
    {
        cout << "1\n";
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
    return 0;
}