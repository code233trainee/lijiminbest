#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int primes[4] = {2, 3, 5, 7};
int64 count(int64 n) {
    int64 res = n;
    for(int mask = 1; mask < (1<<4); mask++) {
        int64 prod = 1;
        int bits = 0;
        for(int i = 0; i < 4; i++) {
            if (mask & (1<<i)) {
                prod *= primes[i];
                bits++;
            }
        }
        if (prod > n) continue;
        if (bits & 1) res -= n / prod;
        else          res += n / prod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int64 l, r;
        cin >> l >> r;
        
        int64 ans = count(r) - count(l-1);
        cout << ans << "\n";
    }
    return 0;
}
