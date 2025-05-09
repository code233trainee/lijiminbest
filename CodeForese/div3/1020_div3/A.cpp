#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j == i)
            {
                if(s[j] == '0')
                {
                    cnt++;
                }
                continue;
            }
            if(s[j] == '1')
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}