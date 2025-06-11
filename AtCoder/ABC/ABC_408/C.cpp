#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> diff(n+2);
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        diff[x]++;
        diff[y+1]--;
    }
    for(int i = 1; i <= n; i++)
    {
        diff[i] = diff[i-1] + diff[i];
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        ans = min(ans, diff[i]);
    }
    cout << ans << endl;
    return 0;
}