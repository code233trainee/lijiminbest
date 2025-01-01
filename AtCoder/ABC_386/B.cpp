#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    int ans = 0;
    for(i = 0; i < n;)
    {
        if(s[i] >= '1' && s[i] <= '9')
        {
            ans++;
            i++;
        }
        else
        {
            int cnt = 0;
            while(s[i] == '0')
            {
                cnt++;
                i++;
            }
            ans += (cnt + 1) / 2;
        }
    }
    cout << ans << "\n";
    return 0;
}