#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x;
    cin >> x;
    if (x == 1 || x == 2 || x == 3) 
    {
        cout << -1 << '\n';
        return;
    }
    if (x % 2 == 1) 
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
