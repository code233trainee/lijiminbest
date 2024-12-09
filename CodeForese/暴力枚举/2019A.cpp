#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mx0 = 0;
    int mx1 = 0;
    int mxindex = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i&1)
        {
            if(a[i] > mx1)
            {
                mx1 = a[i];
            }
        }
        else
        {
            if(a[i] > mx0)
            {
                mx0 = a[i];
            }
        }
    }
    cout << max(mx1 + n/2, mx0 + (n+1)/2) << endl;
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