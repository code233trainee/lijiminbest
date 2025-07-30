#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s = "$aeiou";
    int m = n % 5;
    for(int i = 1; i <= min(5, n); i++)
    {
        for(int j = 1; j <= n/5; j++)
        {
            cout << s[i];
        }
        if(i <= m)
        {
            cout << s[i];
        }
    }
    cout << "\n";
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