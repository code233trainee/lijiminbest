#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool cmp(ll a, ll b)
{
    return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    ll ans = INT_MIN;
    int quest = 0;
    // sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < m; i++)
    {
        ll temp = 0;
        int cnt = 0;
        for(int j = 0; j < m; j++)
        {
            if(a[j] >= a[i])
            {
                cnt++;
            }
        }
        if(cnt >= n)
        {
            cnt = n;
        }
        temp = cnt*a[i];
        if(temp > ans)
        {
            ans = temp;
            quest = a[i];
        }
    }
    cout << quest << " " << ans << endl;
    return 0;
}