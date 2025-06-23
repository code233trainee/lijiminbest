#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> p(n+1);
        vector<int> d(n+1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        for (int i = 1; i <= n; i++) cin >> d[i];
        int q;
        cin >> q;
        vector<ll> a(q);
        for (int i = 0; i < q; i++) cin >> a[i];

        int N = n * 2 * k;
        vector<char> status(N, 0);
        vector<char> result(N, 0);

        auto encode = [&](int i, int dir, int t) {
            int di = (dir==1?0:1);
            return ((i-1)*2 + di)*k + t;
        };
        auto decode = [&](int id, int &i, int &dir, int &t) {
            t = id % k;
            int tmp = id / k;
            int di = tmp % 2;
            dir = (di==0?1:-1);
            i = tmp/2 + 1;
        };
        
        auto next_id = [&](int id) {
            int i, dir, t;
            decode(id, i, dir, t);
            int ndir = dir;
            if (t == d[i]) ndir = -dir;
            if (ndir == 1) {
                if (i == n) return -1;
                ll L = p[i+1] - p[i];
                int nt = (t + (L % k)) % k;
                return encode(i+1, ndir, nt);
            } else {
                if (i == 1) return -1;
                ll L = p[i] - p[i-1];
                int nt = (t + (L % k)) % k;
                return encode(i-1, ndir, nt);
            }
        };

        vector<int> stack;
        stack.reserve(N);
        for (int s = 0; s < N; s++) {
            if (status[s] != 0) continue;
            int cur = s;
            stack.clear();
            while (true) {
                if (status[cur] == 0) {
                    status[cur] = 1;
                    stack.push_back(cur);
                    int nx = next_id(cur);
                    if (nx < 0) {
                        
                        for (int u : stack) {
                            status[u] = 3;
                        }
                        break;
                    }
                    if (status[nx] == 1) {
                        auto it = find(stack.begin(), stack.end(), nx);
                        for (auto jt = it; jt != stack.end(); ++jt) {
                            status[*jt] = 2;
                        }
                        for (auto jt = stack.begin(); jt != it; ++jt) {
                            status[*jt] = 2;
                        }
                        break;
                    }
                    if (status[nx] == 2 || status[nx] == 3) {
                        char res = (status[nx] == 3 ? 3 : 2);
                        for (int u : stack) status[u] = res;
                        break;
                    }
                    cur = nx;
                } else {
                    break;
                }
            }
        }
        for (ll ai : a) {
            if (ai < p[1]) {
                cout << "YES\n";
                continue;
            }
            if (ai > p[n]) {
                cout << "YES\n";
                continue;
            }
            int j = int(lower_bound(p.begin()+1, p.begin()+n+1, ai) - (p.begin()+1)) + 1;
            if (p[j] != ai) {
                ll L = p[j] - ai;
                int t0 = int(L % k);
                int sid = encode(j, +1, t0);
                cout << (status[sid] == 3 ? "YES" : "NO") << '\n';
            } else {
                int sid = encode(j, +1, 0);
                cout << (status[sid] == 3 ? "YES" : "NO") << '\n';
            }
        }
    }
    return 0;
}
