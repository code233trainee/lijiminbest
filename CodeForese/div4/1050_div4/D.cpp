#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> odd, even;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x % 2)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
            ans += x;
        }
    }
    sort(odd.begin(), odd.end(), greater<int>());
    // sort(even.begin(), even.end(), greater<int>());
    if(odd.size() == 0)
    {
        cout << 0 << endl;
        return;
    }
    int len = (odd.size() + 1) / 2;
    for(int i = 0; i < len; i++)
    {
        ans += odd[i];
    }
    cout << ans << endl;
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