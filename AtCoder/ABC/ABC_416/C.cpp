#include <bits/stdc++.h>
using namespace std;

int N, K;
long long X;
vector<string> S;
vector<string> all_strs;

void dfs(int depth, string &cur) {
    if (depth == K) {
        all_strs.push_back(cur);
        return;
    }
    for (int i = 0; i < N; i++) {
        int prev_len = cur.size();
        cur += S[i];
        dfs(depth + 1, cur);
        cur.resize(prev_len);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> X;
    S.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    string tmp;
    dfs(0, tmp);

    sort(all_strs.begin(), all_strs.end());
    cout << all_strs[X - 1] << "\n";
    return 0;
}
