#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m);
    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while(q--)
    {
        int x;
        cin >> x;
        if(x < a[0])
        {
            cout << a[0] - 1 << endl;
            continue;
        }
        if(x > a[m-1])
        {
            cout << n - a[m-1] << endl;
            continue;
        }
        // 找到第一个大于等于x的元素位置(题目说肯定都是不同的点)
        auto it = upper_bound(a.begin(), a.end(), x);
        int r = *it;
        it--;
        int l = *it;
        cout << (r - l) / 2 << endl;
    }
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