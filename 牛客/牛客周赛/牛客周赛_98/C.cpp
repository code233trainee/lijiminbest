#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    static const vector<char> C = {'r','e','d'};
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            for (char c : C) {
                if (c != s[i-1] && (i+1 == n || c != s[i+1])) {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << "\n";
    return 0;
}
