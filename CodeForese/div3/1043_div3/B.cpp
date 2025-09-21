#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> ans;
    ll a = 10;
    while(n >= a+1)
    {
        if(n % (a + 1) == 0)
        {
            ans.push_back(n / (a + 1));
        }
        a *= 10;
    }
    cout << ans.size() << endl;
    if(ans.size() == 0)
    {
        return;
    }
    else
    {
        for(int i = ans.size()-1; i >= 0; i--)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
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