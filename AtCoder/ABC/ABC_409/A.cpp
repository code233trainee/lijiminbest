#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'o' && t[i] == 'o')
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}