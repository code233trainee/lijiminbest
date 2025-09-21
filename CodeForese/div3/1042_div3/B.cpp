#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            a[i] = -1;
        }
        else
        {
            a[i] = 3;
        }
    }
    if(n % 2 == 0)
    {
        a[n-1] = 2;
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n-1];
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