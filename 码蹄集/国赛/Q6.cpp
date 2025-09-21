#include <bits/stdc++.h>
using namespace std;
int istrue(string s)
{
    int l = 0, r = s.size() - 1;
    while(l <= r)
    {
        if(s[l] != s[r])
        {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            string t = s.substr(i, j - i + 1);
            ans += istrue(t);
        }
    }
    cout << ans << endl;
    return 0;
}