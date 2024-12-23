#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    vector<int> a(26);
    vector<int> b(26);
    int sl = s.length();
    int tl = t.length();
    for(int i = 0; i < sl; i++)
    {
        a[s[i] - 'a']++;
    }
    for(int i = 0; i < tl; i++)
    {
        b[t[i] - 'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++)
    {
        ans += min(a[i], b[i]);
    }
    cout << ans;
    return 0;
}