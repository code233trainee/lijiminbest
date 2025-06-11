#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnta = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'a')
        {
            cnta++;
        }
    }
    if(n == cnta)
    {
        s[n-1] = 'z';
    }
    else
    {
        bool ok = false;
        for(int i = 0; i < n; i++)
        {
            while(s[i] != 'a' && i < n)
            {
                s[i] -= 1;
                i++;
                ok = true;
            }
            if(ok)
            {
                break;
            }
        }
    }
    cout << s << endl;
    return 0;
}