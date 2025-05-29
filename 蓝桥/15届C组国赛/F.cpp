#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for(int x = 1; x <= 1e6; x++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if((a[i] + x) % k <= t)
            {
                sum++;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}