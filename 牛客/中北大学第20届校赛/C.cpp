#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    ll cntt = 0, cnttq = 0, cnttqw = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 't')
        {
            cntt += 1;
        }
        else if(s[i] == 'q')
        {
            cnttq += cntt;
        }
        else if(s[i] == 'w')
        {
            cnttqw += cnttq;
        }
    }
    cout << cnttqw;
    return 0;
}