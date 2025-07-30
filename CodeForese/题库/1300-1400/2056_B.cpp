// https://codeforces.com/problemset/problem/2056/B
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<string> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    sort(a.begin(), a.end(), 
    [&](int x, int y)
    {
        if(vs[x][y] == '1')
        {
            return x < y;
        }
        else
        {
            return y < x;
        }
    });
    for(auto &z : a)
    {
        cout << z+1 << " ";
    }
    cout << "\n";
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