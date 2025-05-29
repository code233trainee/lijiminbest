#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            cnt1++;
        }
    }
    cnt0 = n - cnt1;
    int half = n / 2;

    if(cnt0 < n/2 - k || cnt1 < n/2 - k)
    {
        cout << "NO\n";
    }
    else
    {
        cnt0 -= n/2 - k;
        if(cnt0 % 2 != 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout <<"YES\n";
        }
    }
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
