#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> C(n);
    for(int i = 0; i < n; i++)
    {
        cin >> C[i];
    }

    vector<int> pw(n+1);
    pw[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        pw[i] = pw[i - 1] * 3;
    }

    vector<vector<int>> a(n);
    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        for(int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            x--;
            a[x].push_back(i);
        }
    }

    ll ans = 1E18;
    for(int mask = 0; mask < pw[n]; mask++)
    {
        vector<int> cnt(m);
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            int t = mask / pw[i] % 3;
            for(int p = 0; p < t; p++)
            {
                for(auto z : a[i])
                {
                    cnt[z]++;
                }
                res += C[i];
            }
        }
        if(*(min_element(cnt.begin(), cnt.end())) >= 2)
        {
            ans = min(ans, res);
        }
    }
    cout << ans << "\n";
    return 0;
}