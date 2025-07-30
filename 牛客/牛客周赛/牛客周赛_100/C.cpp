#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(2*n+1);
    for(int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
    }
    int p = 1;
    for(int i = 2; i <= 2*n; i++)
    {
        if(a[i] == a[p])
        {
            p = i+1;
            i++;
        }
    }
    cout << (p == 2*n+1 ? "Yes" : "No") << "\n";
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