#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    ll b;
    cin >> s >> b;
    int n = s.length();
    ll sum2 = 0, sum4 = 0, sum8 = 0, sum16 = 0;
    ll cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] >= '0' && s[i] <= '1')
        {
            sum2 += (ll)pow(2, cnt) * (s[i] - '0');
            cnt++;
        }
        else
        {
            sum2 = -1;
            break;
        }
        if(sum2 > b)
        {
            sum2 = -1;
            break;
        }
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] >= '0' && s[i] <= '3')
        {
            sum4 += (ll)pow(4, cnt) * (s[i] - '0');
            cnt++;
        }
        else
        {
            sum4 = -1;
            break;
        }
        if(sum4 > b)
        {
            sum4 = -1;
            break;
        }
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] >= '0' && s[i] <= '7')
        {
            sum8 += (ll)pow(8, cnt) * (s[i] - '0');
            cnt++;
        }
        else
        {
            sum8 = -1;
            break;
        }
        if(sum8 > b)
        {
            sum8 = -1;
            break;
        }
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            sum16 += (ll)pow(16, cnt) * (s[i] - '0');
            cnt++;
        }
        else if(s[i] >= 'A' && s[i] <= 'F')
        {
            sum16 += (ll)pow(16, cnt) * ((s[i] - 'A')+10); 
            cnt++;
        }
        else
        {
            sum16 = -1;
            break;
        }
        if(sum16 > b)
        {
            sum16 = -1;
            break;
        }
    }
    ll count = 0;
    ll ans = 0;
    if(sum2 != -1 && sum2 <= b)
    {
        count++;
        ans = sum2;
    }
    if(sum4 != -1 && sum4 <= b)
    {
        count++;
        ans = sum4;
    }
    if(sum8 != -1 && sum8 <= b)
    {
        count++;
        ans = sum8;
    }
    if(sum16 != -1 && sum16 <= b)
    {
        count++;
        ans = sum16;
    }
    if(count == 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}   
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        solve();
    }
    return 0;
}