#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if(n < 2)
    {
        cout << s << "\n";
        return 0;
    }
    int cnt = 1;
    for(int i = n - 1; i >= 1; i--)
    {
        if(s[i] == s[i-1])
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    for(int i = n - cnt - 1; i >= 0; i--)
    {
        s += s[i];
    }
    cout << s << "\n";
    return 0;
}