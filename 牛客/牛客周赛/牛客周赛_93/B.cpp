#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i < n - 4; i++)
    {
        if(s[i] == s[i+2] && s[i] == s[i+4] && s[i] != s[i+1] && s[i+1] == s[i+3])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}