#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, v[2010], w[2010];
void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        //w是价值， v是体积
        cin >> v[i] >> w[i];
    }
    int real_ans = 0;
    for(int ans = 0; ans <= 2010; ans++)
    {
        //越与越小，所以vsum肯定需要很大
        int vsum = (1 << 20) - 1;
        for(int i = 1; i <= n; i++)
        {
            if((w[i]&ans) == ans)
            {
                vsum &= v[i];
            }
        }
        if(vsum <= k)
        {
            real_ans = max(real_ans, ans);
        }
    }
    cout << real_ans << "\n";
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}