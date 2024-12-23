#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> fei(46);
void solve()
{
    ll n;
    cin >> n;
    ll temp = n;
    stack<ll> ans;
    for(int i = 45; i >= 1; i--)
    {
        while(n >= fei[i])
        {
            ans.push(fei[i]);
            n -= fei[i];
        }
        if(n == 0)
        {
            break;
        }
    }
    cout << temp << '=';
    while(ans.size())
    {
        if(ans.size() == 1)
        {
            cout << ans.top() << "\n";
            ans.pop();
            break;
        }
        cout << ans.top();
        cout << '+';
        ans.pop();
    }
}
int main()
{
    fei[0] = 0;
    fei[1] = 1;
    for(int i = 2; i <= 45; i++)
    {
        fei[i] = fei[i-1] + fei[i-2];
    }
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}