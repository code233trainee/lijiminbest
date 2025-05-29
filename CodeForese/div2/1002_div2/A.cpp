#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<int, int> a, b;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    if(b.size() == 1 && a.size() <= 2)
    {
        cout << "NO\n";
    }
    else if(b.size() <= 2 && a.size() == 1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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