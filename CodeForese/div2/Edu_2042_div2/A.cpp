#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    //从大到小排序
    return a > b;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), cmp);
    int temp = 0;
    int i = 0;
    for(i = 0; i < n; i++)
    {
        temp += a[i];
        if(temp >= k)
        {
            break;
        }
    }
    if(temp > k)
    {
        temp -= a[i];
    }
    cout << abs(temp - k) << endl;
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