#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> a(n+1);
    vector<bool> mx(n+1);
    while(q--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int i, j;
            cin >> i >> j;
            a[i].insert(j);
        }
        else if(x == 2)
        {
            int i;
            cin >> i;
            mx[i] = true;
        }
        else if(x == 3)
        {
            int i, j;
            cin >> i >> j;
            if(mx[i] || a[i].count(j))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}