#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
void solve()
{
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int num = a[f];
    sort(a.begin()+1, a.end(), cmp);
    int cnt = count(a.begin()+1, a.end(), num);
    // 严格大于目标值:upper_bound
    // 大于或者等于目标值:lower_bound
    int ind;
    for(ind = 1; ind <= n; ind++)
    {
        if(a[ind] == num)
        {
            break;
        }
    }
    if(ind > k)
    {
        cout << "NO\n";
    }
    else if(ind + cnt - 1 > k)
    {
        cout << "MAYBE\n";
    }
    else
    {
        cout << "YES\n";
    }
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