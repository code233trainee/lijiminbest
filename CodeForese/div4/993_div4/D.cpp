#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1, 0), vis(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (!vis[a[i]]) {
            b[i] = a[i];
            vis[a[i]] = 1;
        }
    }

    int current = 1; 
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            while (vis[current]) current++;
            b[i] = current;
            vis[current] = 1;
        }
    }

    for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];

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