#include <bits/stdc++.h>
using namespace std;
string s[200005];
map<char, int> mp[200005];
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int len, n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    len = s[0].size();
    for(int i = 1; i < n; i++)
    {
        int a = s[i].size();
        len = gcd(len, a);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < s[i].size(); j++)
        {
            mp[j%len][s[i][j]]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < len; i++)
    {
        int mx = 0;
        int sum = 0;
        for(auto z : mp[i])
        {
            sum += z.second;
            mx = max(mx, z.second);
        }
        ans += sum - mx;
    }
    cout << ans << endl;
    return 0;
}