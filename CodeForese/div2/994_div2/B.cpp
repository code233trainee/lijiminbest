#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if(s[0] == 's')
    {
        s[0] = '.';
    }
    if(s.back() == 'p')
    {
        s.back() = '.';
    }
    bool found_p = false;
    bool found_s = false;
    for(const auto c : s)
    {
        //剩下的字符全是p，或者全是s时才为YES
        switch(c)
        {
            case 'p':
                found_p = true;
                break;
            case 's':
                found_s = true;
                break;
        }
    }
    cout << (found_p && found_s ? "NO" : "YES") << "\n";
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