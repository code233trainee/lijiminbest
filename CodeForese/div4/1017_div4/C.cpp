#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2*n+1);
    vector<bool> check(2*n+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int b;
            cin >> b;
            a[i+j] = b;
            check[b] = true;
        }
    }
    for(int i = 1; i <= 2*n; i++)
    {
        if(!check[i])
        {
            a[1] = i;
        }
    }
    for(int i = 1; i <= n*2; i++)
    {
        cout << a[i] << " \n"[i == 2*n];
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