#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;

int main() {

    ll a;
    int k;
    cin >> a >> k;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    unordered_set<ll> vis;
    vis.reserve(k * 2);

    pq.push(a);
    vis.insert(a);

    ll ans = a;
    for (int i = 0; i < k; i++) {
        ll x = pq.top(); 
        pq.pop();
        ans = x;
        ll y1 = 3*x + 5;
        if (y1 > 0 && vis.insert(y1).second) {
            pq.push(y1);
        }
        ll y2 = 2*x - 10;
        if (y2 > 0 && vis.insert(y2).second) {
            pq.push(y2);
        }
    }

    cout << ans << "\n";
    return 0;
}
