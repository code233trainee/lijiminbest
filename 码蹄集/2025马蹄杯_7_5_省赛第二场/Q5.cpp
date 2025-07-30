#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> ma;
    set<int> se;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ma[x]++;
        se.insert(x);
    }
    int k = -1;
    for(auto z : ma)
    {
        if(z.second > k)
        {
            k = z.second;
        }
    }
    for(auto z : se)
    {
        if(ma[z] == k)
        {
            cout << z << "\n";
        }
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