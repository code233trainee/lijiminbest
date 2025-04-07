#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k, v[200010], w[200010];
int main()
{
    //F题的答案交到E题也可以通过
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    ll ans = 0;
    for(int bt = 30; bt >= 0; bt--)
    {
        ll try_ans = ans | (1ll << bt);
        ll vsum = (1ll << 40) - 1ll;
        for(int i = 1; i <= n; i++)
        {
            //我们想要加上当前这个物品后，他的总价值不变(当前枚举的)
            if((w[i] & try_ans) == try_ans)
            {
                vsum &= v[i];
            }
        }
        if(vsum <= k)
        {
            ans = try_ans;
        }
    }
    cout << ans << "\n";
    return 0;
}