#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int p = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == k)
        {
            p = i;
        }
    }
    int l = 0, r = n;
    while(r - l > 1)
    {
        int mid = (l + r) / 2;
        if(a[mid] <= k)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << "1\n";
    cout << p + 1 << " " << l + 1 << "\n";
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