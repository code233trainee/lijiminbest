#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == s[i+1])
        {
            cnt++;
            i++;
        }
        else if(s[i] == '?' || s[i+1] == '?')
        {
            cnt++;
            i++;
        }
    }   
    cout << cnt;
    return 0;
}