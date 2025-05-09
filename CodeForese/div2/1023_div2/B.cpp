#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int mx = *(max_element(a.begin(), a.end()));
    int mn = *(min_element(a.begin(), a.end()));
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == mx)
        {
            cnt++;
        }
    }
    ll d = mx - mn;
    if(d - 1 > k || d > k && cnt > 1)
    {
        cout << "Jerry\n";
        return;
    }
    else
    {
        if (sum % 2 == 1)
        {
            cout << "Tom\n";
        }
        else 
        {
            cout << "Jerry\n";
        }
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