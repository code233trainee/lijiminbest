#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(26);
    vector<int> sum(26);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int last = s[0] - 'a';
    for(int i = 0; i < n; i++)
    {
        if(sum[s[i] - 'a'] != 0)
        {
            if(sum[s[i] - 'a'] > a[s[i] - 'a'])
            {
                if(sum[s[i] - 'a'] % a[s[i] - 'a'] != 0)
                {
                    cout << "No\n";
                    return;
                }
            }
            else if(sum[s[i] - 'a'] < a[s[i] - 'a'])
            {
                cout << "No\n";
                return;
            }
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if(sum[i] > a[i])
        {
            if(sum[i] % a[i] != 0)
            {
                cout << "No\n";
                return;
            }
        }
        else if(sum[i] < a[i])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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