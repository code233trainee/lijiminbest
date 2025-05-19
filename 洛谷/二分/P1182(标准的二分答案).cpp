#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int r = 0, l = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    auto check = [&](int x) -> bool {
        int total = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(total + a[i] <= x)
            {
                total += a[i];
            }
            else
            {
                total = a[i];
                cnt++;
            }
        }
        return cnt >= m;
    };
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << l << endl;
    return 0;
}