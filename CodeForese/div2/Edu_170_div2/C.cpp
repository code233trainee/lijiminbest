#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0;

    // O(nlogn)的时间
    for(int i = 0, j = 0; i < n; i++)
    {
        j = max(j, i);
        while(j + 1 < n && a[j + 1] <= a[j] + 1 && a[j + 1] < a[i] + k)//每次选择当前从i开始最大的数量
        {//既然我们确定了选择的牌是连续的，那么不同的牌就可以(a[j + 1] < a[i] + k)这样来确定
            j++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}