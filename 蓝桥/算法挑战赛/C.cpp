#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    vector<array<int, 26>> cnt(4);
    for (int i = 0; i < n; i++) {
        int k = i % 4;
        cnt[k][S[i] - 'a']++;
    }

    int ans = 0;
    for (int r = 0; r < 4; r++) {
        int cb = cnt[r][ 'b' - 'a' ];
        int cl = cnt[(r+1)%4][ 'l' - 'a' ];
        int cu = cnt[(r+2)%4][ 'u' - 'a' ];
        int ce = cnt[(r+3)%4][ 'e' - 'a' ];
        ans = max(ans, min({cb, cl, cu, ce}));
    }

    cout << ans << "\n";
    return 0;
}
