#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    if(a[n-1] != b[n-1])
    {
        cout << "NO\n";
        return;
    }
    for(int i = n-2; i >= 0; i--)
    {
        // int k = a[i]^a[i+1];
        // int x = a[i]^b[i+1];
        // cout << k << endl;
        // cout << x << endl;
        if((a[i] ^ a[i+1]) != b[i] && (a[i] ^ b[i+1]) != b[i] && a[i] != b[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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