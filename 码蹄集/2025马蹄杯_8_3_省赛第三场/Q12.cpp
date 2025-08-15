#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    map<string, int> ma;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ma[s]++;
    }
    int q;
    cin >> q;
    while(q--)
    {
        int op;
        string s;
        int num;
        cin >> op ;
        if(op == 1)
        {
            cin >> s >> num;
            if(ma[s] >= 1)
            {
                ma[s] += num;
            }
        }
        else
        {
            cin >> s;
            if(ma[s] >= 1)
            {
                cout << ma[s] - 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
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