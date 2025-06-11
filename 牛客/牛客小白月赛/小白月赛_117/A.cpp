#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> n >> s;
    vector<int> low(26);
    vector<int> hai(26);
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            low[s[i] - 'a']++;
        }
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            hai[s[i] - 'A']++;
        }
    }
    for(int i = 0; i < 26; i++)
    {
        if((low[i] >= 1 && hai[i] < 1) || (low[i] < 1 && hai[i] >= 1))
        {
            cout << "NO\n";
        }
    }
    cout << "YES\n";
    return 0;
}