#include <bits/stdc++.h>
using namespace std;
void solve()
{
    // 3 3 2 n=3 k=2(×)
    // 2 3 2 (√)
    // n=5 k=2: 4 4 4 5 4
    int n, k;
    cin >> n >> k;
    vector<int> ans(n+1);
    if(k%2==0)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == n-1)
            {
                cout << n << "\n";
            }
            else
            {
                cout << n - 1 << " ";
            }
        }
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == n)
            {
                cout << n - 1 << "\n";
            }
            else
            {
                cout << n << " ";
            }
        }
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