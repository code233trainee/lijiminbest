#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    set<int> se;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        se.insert(x);
    }
    int now = 0;
    for(auto z : se)
    {
        if(z != now)
        {
            cout << now << endl;
            return;
        }
        now++;
    }
    cout << now << endl;
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