#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2010);
    vector<int> c(2010);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    for(int i = 1; i <= n * 2 + 1; i++)
    {
        if(!c[i])
        {
            continue;
        }
        if(c[i] == 1)
        {
            cout << "No\n";
            return;
        }
        c[i+1] += c[i]-2;
        c[i] -= 2;
    }
    cout << "Yes\n";
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