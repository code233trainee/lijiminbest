#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(k == n)
    {
        int i = 2;
        for(i = 2; i <= n; i += 2)
        {
            if(a[i] != i/2)
            {
                cout << i/2 << endl;
                return;
            }
        }
        cout << k/2 + 1 << endl;
        
    }
    else
    {
        for(int i = 2; i <= n - k + 2; i++)
        {
            if(a[i] != 1)
            {
                cout << "1\n";
                return;
            }
        }
        cout << "2\n";
    }
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