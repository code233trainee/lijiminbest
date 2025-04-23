#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int q;
    cin >> q;
    queue<int> qu;
    while(q--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int c;
            cin >> c;
            qu.push(c);
        }
        else
        {
            cout << qu.front() << endl;
            qu.pop();
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