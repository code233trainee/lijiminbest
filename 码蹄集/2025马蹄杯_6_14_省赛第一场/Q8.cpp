#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = n - 1;
    int ans = 0;
    while(l < r)
    {
        if(s[l] != s[r])
        {
            ans++;
        }
        l++;
        r--;
    }
    cout << ans << endl;
    return 0;
}