#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
ll n, m, v, s[N], pf[N], sf[N];
//动态规划，前缀和
void solve()
{
    cin >> n >> m >> v;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i-1];
    }
    s[n+1] = s[n];
    ll s1 = 0, s2=0;
    for(int i = 1, lst = 0; i <= n; i++)
    {
        if(s[i] - s[lst] >= v)
        {
            pf[++s1] = lst = i;
        }
    }
    s1 = min(s1, m);
    for(int i = n, lst = n + 1; i >= 1; i--)
    {
        if(s[lst-1] - s[i-1] >= v)
        {
            sf[++s2] = lst = i;
        }
    }
    sf[0] = n + 1;
    s2 = min(s2, m);
    ll ans = -1;
    for(int i = m - s2; i <= s1; i++)
    {
        if(pf[i] < sf[m-i])
        {
            ans = max(ans, s[sf[m - i] - 1] - s[pf[i]]);
        }
    } 
    cout << ans << endl;
}
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}