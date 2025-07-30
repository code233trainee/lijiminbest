#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        a[i] = i + a[i-1]; 
    }
    ll ans = a[n];
    int cnt1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            cnt1++;
        }
    }
    if(!cnt1)
    {
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        ll cnt = 0;
        while(s[i] == '0' && i < n)
        {
            cnt++;
            i++;
        }
        if(cnt)
        {
            sum += a[cnt];
        }
    }
    cout << ans - sum << endl;
    return 0;
}