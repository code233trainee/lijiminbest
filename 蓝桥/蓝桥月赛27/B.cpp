#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    ll l = 0, la = 0, lan = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'l')
        {
            l++;
        }
        else if(s[i] == 'a')
        {
            la += l;
        }
        else if(s[i] == 'n')
        {
            lan += la;
        }
    }
    cout << lan;
    return 0;
}