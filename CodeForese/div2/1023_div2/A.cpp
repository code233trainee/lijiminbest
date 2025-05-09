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
        cin >> a[i];
    }
    int mx = *(max_element(a.begin(), a.end()));
    int mn = *(min_element(a.begin(), a.end()));
    if(mn == mx)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++)
    {
        if(a[i] == mx)
        {
            cout << "2 ";
        }
        else
        {
            cout << "1 ";
        }
    }
    cout << "\n";
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