#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    if(n == m || n - m > 26) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string ans(n, 'a');
    int x = n - m;
    for(int i = 0; i < n; i++) {
        ans[i] = char('a' + i % x);
    }
    cout << ans << "\n";

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