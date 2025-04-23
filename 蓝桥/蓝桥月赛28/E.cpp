#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
int main()
{
    ll n;
    cin >> n;
    unordered_set<ll> st;
    ll ans = 1;
    for(int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        if(st.find(x) != st.end())
        {
            cout << "0\n";
            return 0;
        }
        st.insert(x);
    }
    for(auto it = st.begin(); it != st.end(); it++)
    {
        for(auto it2 = next(it); it2 != st.end(); it2++)
        {
            ans *= *it ^ *it2;
            ans %= MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}