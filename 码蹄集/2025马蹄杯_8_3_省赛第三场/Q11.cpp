#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    string s;
    cin >> s;
    int cnt1 = 0;
    int cnt0 = 0;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            cnt1++;
        }
    }
    int pos = -1;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == '1')
        {
            pos = i;
            break;
        }
    }
    cnt0 = pos + 1 - cnt1;
    if(cnt1 <= 1)
    {
        cout << "BBB\n";
        return;
    }
    if(cnt0 % 2 == 0)
    {
        
    }
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