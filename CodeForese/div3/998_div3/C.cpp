#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int a[N];
map<int, int> mp;
void solve()
{
    int n, k;
    cin >> n >> k;
    mp.clear();
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    
    //直接匹配
    //先选的想要得分最低，但是每一个有无得分的对都可以被后选的选上
    //所以这个问题就变成了这个序列最多有多少对匹配的数字加起来为k
    for(int i = 1; i <= n; i++)
    {
        if(mp[k - a[i]] > 0)//如果有可用的数
        {
            mp[k - a[i]]--;//将这个数去掉
            ans++;
        }
        else
        {
            mp[a[i]]++;//没有可用的数就将这个数加入
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}