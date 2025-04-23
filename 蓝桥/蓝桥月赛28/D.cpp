#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 1; i <= n-1; i++)
    {
        cin >> a[i];
    }   
    int ans = 0;
    int l = 1, r = 1;
    while(r < n)
    {
        int maxr = r;
        for(int i = l; i <= r; i++)
        {
            maxr = max(maxr, a[i]);
        }
        l = r + 1;
        r = maxr;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}