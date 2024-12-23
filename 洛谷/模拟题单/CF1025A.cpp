#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    if(n == 1)
    {
        cout << "yes" << "\n";
        return 0;
    }
    vector<int> a(26);
    for(int i = 0; i < n; i++)
    {
        a[s[i]-'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(a[i] >= 2)
        {
            cout << "yes" << "\n";
            return 0;
        }
    }
    cout << "no" << "\n";
    return 0;
}