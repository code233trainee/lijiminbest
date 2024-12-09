#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 0; 
    int r = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        l = i;
        r = i;
        while(a[l-1] <= a[l] && l > 1)
        {
            l--;
        }
        while(a[r+1] <= a[r] && r < n)
        {
            r++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans << "\n";
    return 0;
}