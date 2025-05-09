#include <bits/stdc++.h>
using namespace std;
int main()
{
    string t, u;
    cin >> t >> u;
    int n = u.length();
    int j = 0;
    for(int i = 0; i + n <= t.length(); i++)
    {
        string s = t.substr(i, n);
        int j = 0;
        for(; j < n; j++)
        {
            if(s[j] == u[j] || s[j] == '?')
            {
                continue;  
            }
            else
            {
                break;
            }
        }
        if(j == n)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    
    return 0;
}