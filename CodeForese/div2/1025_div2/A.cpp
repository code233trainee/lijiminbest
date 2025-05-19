#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt0 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            cnt0++;
        }
    }
    if(!cnt0)
    {
        cout << "YES\n";
        return;
    }
    for(int i = 0; i < n - 1; i++)
    {
        if((a[i] == 0 && a[i+1] == 0))
        {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
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