#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> se;
    map<int, int> ma;
    map<int, int> change;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
        ma[a[i]]++;
    }
    int cnt = 0;
    for(auto z : se)
    {
        change[z] = cnt + 1;
        cnt += ma[z];
    }
    for(int i = 0; i < n; i++)
    {
        a[i] = change[a[i]];
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
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