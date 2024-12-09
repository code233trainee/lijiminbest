#include <bits/stdc++.h>
using namespace std;
long long score(vector<int> &p, vector<int> &a, int s, int k)
{
    int n = p.size();
    long long mx = 0;
    long long cur = 0;
    //初始为false
    vector<bool> vis(n);
    //我知道了
    //这是在判断排列的一个循环中两位玩家能够得到的最大值
    //因为每个玩家都想要赢，就只能找到循环中最大的那个值
    while(!vis[s] && k > 0)
    {
        vis[s] = 1;
        //乘上k就是判断如果一直留在当前的点能否获得最大值
        mx = max(mx, cur + 1ll * k * a[s]);
        cur += a[s];//用cur来进一步移动
        k--;
        s = p[s];
    }
    return mx;
}
void solve()
{
    int n, k, Pb, Ps;
    cin >> n >> k >> Pb >> Ps;
    vector<int> p(n), a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long A = score(p, a, Pb - 1, k);
    long long B = score(p, a, Ps - 1, k);
    cout << (A > B ? "Bodya\n" : A < B ? "Sasha\n" : "Draw\n");
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}