#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> a;
    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        a[b]++; 
    }
    if(a.size() != 2 || n&1 || ((a.begin())->second != (a.rbegin())->second))
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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