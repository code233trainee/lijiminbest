#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    ll cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '>' && a[i] <= 0)
        {
            a[i] = 1;
            cnt++;
        }
        if(s[i] == '<' && a[i] >= 0)
        {
            a[i] = -1;
            cnt++;
        }
        if(s[i] == 'Z' && a[i-1] > 0 && a[i] <= 0)
        {
            a[i] = 1;
            cnt++;
        }
        if(s[i] == 'Z' && a[i-1] < 0 && a[i] >= 0)
        {
            a[i] = -1;
            cnt++;
        }
    }
    cout << cnt << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}