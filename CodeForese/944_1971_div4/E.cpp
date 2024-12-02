#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k+1), b(k+1);
    for(int i = 1; i <= k; i++)
    {
        //站点距离标志
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++)
    {
        //到达时间
        cin >> b[i];
    }
    while(q--)
    {
        long long c;
        cin >> c;
        int l = 0;
        int r = k;
        //二分
        while(l <= r)
        {
            int mid = l+r >> 1;
            if(a[mid] > c)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if(a[r] == c)
        {
            cout << b[r] << " ";
            continue;
        }
        //初中物理
        long long ans = b[r] + (c-a[r]) * (b[r+1] - b[r]) / (a[r+1] - a[r]);
        cout << ans << " ";
        //ans是到达询问点的时间
    }
    cout << endl;

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}