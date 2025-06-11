#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> costR(n+2, 1e18);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        costR[i] = min(costR[i-1], a[i] * (n - i + 1));
    }
    costR.back() = 0;

    vector<ll> nxt(n+1);
    map<ll, ll> cnt;
    // 双指针找合法区间
    for(int i = n, j = n; i >= 1; i--)
    {
        cnt[a[i]]++;
        while(j > i && cnt[a[i]] > 1)
        {
            cnt[a[j]]--;
            j--;
        }
        nxt[i] = j;
    }

    cnt.clear();
    ll ans = 1e18;
    for(int i = 1; i <= n; i++)
    {
        ll cost = costR[nxt[i] + 1] + (i - 1) * a[i - 1];
        ans = min(ans, cost);
    }
    cout << ans << "\n";
    return 0;
}