#include <bits/stdc++.h>
using namespace std;
vector<int> kmp(string s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
 }
int main() {
    string s;
    while(cin >> s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string t = s + "#" + rev;
        vector<int> pi = kmp(t);
        int mx = pi.back();
        string add = rev.substr(0, s.size()-mx);
        string ans = s + add;
        cout << ans << endl;
    }
    return 0;
}
