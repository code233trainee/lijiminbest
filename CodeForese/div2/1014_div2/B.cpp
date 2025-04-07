#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> cnt(2);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '0')
        {
            cnt[i % 2]++;
        }   
        if(t[i] == '0')
        {
            cnt[(i+1)%2]++;
        }
    }
    if(cnt[0] >= (n+1)/2 && cnt[1] >= n/2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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