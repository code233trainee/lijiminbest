#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
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