#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = '$' + s;
    set<int> se;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '#')
        {
            se.insert(i);
        }
    }
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        if(x > y)
        {
            swap(x, y);
        }
        if(s[y] == '#')
        {
            auto it = se.lower_bound(x);
            cout << y - *it + 1 << "\n";
        }
        else
        {
            auto itx = se.lower_bound(x);
            auto ity = se.lower_bound(y);
            if(itx == ity)
            {
                cout << 0 << "\n";
            }
            else
            {
                ity--;
                cout << *ity - *itx + 1 << "\n"; 
            }
        }
    }
    return 0;
}