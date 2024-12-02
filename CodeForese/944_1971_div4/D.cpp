#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int c01 = 0;
    int c10 = 0;
    for(int i = 1; i < n; i++)
    {
        if(s[i-1] == '1' && s[i] == '0')
        {
            c10++;
        }
        if(s[i-1] == '0' && s[i] == '1')
        {
            c01++;
        }
    }
    //01串只保留一个不切割，所以要减去1
    cout << c10 + max(0, c01 - 1) + 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}