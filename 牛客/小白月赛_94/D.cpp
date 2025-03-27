#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve()
{
    int n;
    cin >> n;
    int ok = 1;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<bool> vis(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i >= 2 && a[i-1] % a[i] != 0)
        {
            ok = 0;
        }
    }
    if(!ok)
    {
        cout << "-1\n";
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != a[i-1])
        {
            b[i] = a[i];
        }
        else
        {
            for(int j = b[i-1] + a[i]; j <= n; j += a[i])
            {
                if(!vis[j] && gcd(a[i-1], j) == a[i])
                {
                    b[i] = j;
                    break;
                }
            }
        }
        if(!b[i])
        {
            cout << -1 << "\n";
            return;
        }
        vis[b[i]] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
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