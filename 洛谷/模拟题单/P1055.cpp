#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int total = 0;
    int cnt = 1;
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            total += int(s[i] - '0') * cnt;
            cnt++;
        }
    }
    total %= 11;
    if(total == 10)
    {
        if(int(s[n-1]) == 'X')
        {
            cout << "Right\n";
        }
        else
        {
            s[n-1] = 'X';
            cout << s << "\n";
        }    
    }
    else
    {
        if(int(s[n-1] - '0') == total)
        {
            cout << "Right\n";
        }
        else
        {
            s[n-1] = to_string(total)[0];
            cout << s << "\n";
        }
    }
    
    return 0;
}