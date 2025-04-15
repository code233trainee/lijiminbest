#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = 0;
    for(int ch = 0; ch < 26; ch++)
    {
        char c = '>';
        int cnt = 0;
        bool isok = true;
        for(int i = 0; i < n; i++)
        {
            if(s[i]-'a' == ch && isok)
            {
                c = t[i];
                isok = false;
            }
            else if(s[i]-'a' == ch && t[i] != c)
            {
                cout << "-1\n";
                return 0;
            }
        }
        if(c -'a' != ch && !isok)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}