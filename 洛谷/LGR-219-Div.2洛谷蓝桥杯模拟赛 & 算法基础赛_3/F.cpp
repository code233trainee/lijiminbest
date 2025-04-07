#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll money = 0, tokens = 0, min_rate = a[0];
    ll max_games = 0; 

    for (int i = 0; i < n; i++) {
        money += b[i];
        min_rate = min(min_rate, a[i]);
        tokens += money / min_rate;
        money %= min_rate;
        
        max_games = max(max_games, tokens / (i + 1));
    }

    cout << max_games << "\n";
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
