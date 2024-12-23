#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int mxl = -1;
    int mxr = -1;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mxl = max(mxl, a);
        mxr = max(mxr, b);
    }
    cout << (mxr + mxl)*2 << "\n";
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