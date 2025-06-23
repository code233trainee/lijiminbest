#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int x = 0, y = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'U')
        {
            y++;
        }
        else if(s[i] == 'D')
        {
            y--;
        }
        else if(s[i] == 'L')
        {
            x--;
        }
        else if(s[i] == 'R')
        {
            x++;
        }
    }
    cout << x << " " << y;
    return 0;
}