#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    for(ll i = 0; i < n; i++) cin >> c[i];
    auto check = [&](vector<ll> &a, vector<ll> &b, vector<ll> &c){
        vector<ll> weight(n);
        for(ll i = 0; i < a.size(); i++)
        {
            weight[i] = a[i] - b[i] - c[i];
        }
        sort(weight.begin(), weight.end());
        ll sum = 0;
        ll cnt = 0;
        for(int i = n-1; i >= 0; i--)
        {
            //累加贡献值
            sum += weight[i];
            //由于是排序后的数组，所以当sum<0的时候后面只会越来越小，可以直接推退出
            if(sum > 0)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        return cnt;
    };
    ll mx = max(check(a, b, c), max(check(b, a, c), check(c, a, b))); 
    if(mx)
    {
        cout << mx << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}