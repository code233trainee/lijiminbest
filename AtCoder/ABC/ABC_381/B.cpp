#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    if(n&1)
    {
        cout << "No" << endl;
    }
    else
    {
        bool isOk = true;
        map<char, int> m;
        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        for(int i = 0; i < n-1; i += 2)
        {
            if(s[i] != s[i+1])
            {
                cout << "No" << endl;
                return 0;
            }
        }
        for(auto z : m)
        {
            if(z.second > 2 || z.second == 1)
            {
                isOk = false;
            }
        }
        if(isOk)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}