#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    set<char> sc;
    for(int i = 0; i < t.size(); i++)
    {
        sc.insert(t[i]);
    }
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(!sc.count(s[i-1]))
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}