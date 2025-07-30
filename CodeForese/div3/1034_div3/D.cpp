#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            cnt1++;
        }
    }
    if(cnt1 <= k)
    {
        cout << "Alice\n";
        return;
    }
    if(k * 2 > n)
    {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
