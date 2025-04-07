#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m, k, q;
        cin >> n >> m >> k >> q;
        if(m * (k-1) >= q)
        {
            if((n - q) % k == 0)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}