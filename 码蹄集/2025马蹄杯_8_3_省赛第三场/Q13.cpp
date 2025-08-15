#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = '$' + s;
    vector<vector<int>> va(26, vector<int>(n+2));
    for(int i = 0; i < 26; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            va[i][j] = va[i][j-1] + ((int)(s[j] - 'a') == i);
        }
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int odd = 0, even = 0;
        for(int i = 0; i < 26; i++)
        {
            if((va[i][r] - va[i][l-1]) % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        cout << even << " " << odd << endl;
    }
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}