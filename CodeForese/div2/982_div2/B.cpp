#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int best = 0;
    for(int i = 0; i < n; i++)
    {
        int curr = 0;
        for(int j = i; j < n; j++)
        {
            if(a[j] <= a[i])
            {
                curr += 1;
            }
        }
        best = max(best, curr);
    }
    cout << n-best << "\n";
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}