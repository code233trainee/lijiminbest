#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;
    deque<char> dq;
    for(int i = 0; i < n; i++)
    {
        dq.push_back(a[i]);
    } 
    for(int i = 0; i < m; i++)
    {
        if(c[i] == 'D')
        {
            dq.push_back(b[i]);
        }
        else
        {
            dq.push_front(b[i]);
        }
    }
    for(int i = 0; i < dq.size(); i++)
    {
        cout << dq[i];
    }
    cout << endl;
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}