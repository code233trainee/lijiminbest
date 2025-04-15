#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pr(m);
    vector<int> diff(n+1);
    vector<int> sum(n+1);
    for(int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
        pr[i-1] = {l, r};
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        diff[i] += diff[i-1];
        sum[i] = sum[i-1] + (diff[i] <= 1);
        if(diff[i] == 0)
        {
            ans++;
        }
    }
    for(int i = 0; i < m; i++)
    {
        cout << sum[pr[i].second] - sum[pr[i].first - 1] + ans << endl;
    }
    return 0;
}