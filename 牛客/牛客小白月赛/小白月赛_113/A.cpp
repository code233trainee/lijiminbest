#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int sum = 1;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '-')
        {
            sum -= 1;
        }
        else if(s[i] == '*')
        {
            sum *= 2;
        }
        if(sum >= 2025)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}