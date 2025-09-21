#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    if(n % 2 == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        if(n == 2)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << "1 3 2 4 ";
            for(int i = 5; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}