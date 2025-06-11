#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int MAXN = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    static int pow2[MAXN + 1];
    pow2[0] = 1;
    for (int i = 1; i <= MAXN; i++) {

        pow2[i] = int((pow2[i - 1] * 2LL) % MOD);
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n), q(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }


        vector<int> r(n);


        int curP_val = -1, curP_idx = -1;
        int curQ_val = -1, curQ_idx = -1;

        for (int i = 0; i < n; i++) {

            if (p[i] > curP_val) {
                curP_val = p[i];
                curP_idx = i;
            }
        
            if (q[i] > curQ_val) {
                curQ_val = q[i];
                curQ_idx = i;
            }

            int L, s;
            if (curP_val > curQ_val) {
            
                L = curP_val;
        
                s = q[i - curP_idx];
            }
            else if (curQ_val > curP_val) {
          
                L = curQ_val;
             
                s = p[i - curQ_idx];
            }
            else {
                
                L = curP_val;

                int c1 = q[i - curP_idx];   
                int c2 = p[i - curQ_idx];   
                s = (c1 > c2 ? c1 : c2);
            }

            int val = pow2[L] + pow2[s];
            if (val >= MOD) val -= MOD;
            r[i] = val;
        }
        for (int i = 0; i < n; i++) {
            cout << r[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
