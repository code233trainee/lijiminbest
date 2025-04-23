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
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        int j = i;
        set<int> s;
        s.insert(a[i]);

        auto check = [&](int x) {
            if(s.size() <= 1)
            {
                return true;
            }
            return (bool)s.count(x);
        };

        while(j + 1 < n && check(a[j+1]))
        {
            s.insert(a[++j]);
        }
        if(s.size() == 1)
        {
            break;
        }
        map<int, int> ma;
        ma[0] = 1;
        int sum = 0;
        for(int k = i; k <= j; k++)
        {
            sum += (a[k] == a[i] ? 1 : -1);
            ans += ma[sum];
            ma[sum] += 1;
        }
        int t = j;
        while(t - 1 >= i && a[t - 1] == a[j])
        {
            t--;
        }
        i = t-1;
    }
    cout << ans << "\n";
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}