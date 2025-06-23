#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int n, x, ans = 1;
map<int, int> mp;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        for(int j = 2; j * j <= x; j++)
        {
            if(x % j == 0)
            {
                int cnt = 0;
                while(x % j == 0)
                {
                    x /= j;
                    cnt++;
                }
                mp[j] = max(mp[j], cnt);
            }
        }
        if(x > 1)
        {
            mp[x] = max(mp[x], 1);
        }
    }
    for(auto p : mp)
    {
        ans = 1ll * ans * (int)pow(p.first, p.second) % mod;
    }
    cout << ans << endl;
    return 0;
}