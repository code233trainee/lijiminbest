#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    ll S = sum / (n - 1);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cout << S - a[i] << " \n"[i == n - 1];
    }
    return 0;
}