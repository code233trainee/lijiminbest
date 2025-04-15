#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'A')
        {
            for(int k = 1; k * 2 < s.length(); k++)
            {
                if(s[i] == 'A' && s[i+k] == 'B' && s[i+2*k] == 'C')
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}