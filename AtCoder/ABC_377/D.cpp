#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef unsigned long long ull;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    // 用 M+1 初始化 min_R
    vector<int> min_R(m+2, m+1);
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        min_R[l] = min(min_R[l], r);
    }
    // 计算后缀最小值
    for(int l = m - 1; l >= 1; l--)
    {
        min_R[l] = min(min_R[l], min_R[l+1]);
    }
    ll total = 0;
    for(int l = 1; l <= m; l++)
    {
        if(min_R[l] > l)
        {
            total += (ll)(min_R[l] - l);
        }
    }
    cout << total;
    return 0;
}