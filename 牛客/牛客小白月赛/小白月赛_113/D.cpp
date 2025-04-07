#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // 不过这题有个结论，答案就是数组中的 max+2 减去数组中值的种类数，手推一下就能发现
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[0] == a[n-1])
    {
        cout << "0\n";
        return 0;
    }
    if(a[0] != 0)
    {
        cout << "-1\n";
        return 0;
    }
    ll cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1])
        {
            cnt += a[i] - a[i-1] - 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}