#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    for(int i = 2; i <= n; i++)
    {
        if(i*2<=n)
        {
            swap(a[i], a[i*2]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n]; 
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}