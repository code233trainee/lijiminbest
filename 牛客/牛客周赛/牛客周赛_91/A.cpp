#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    string t = "while";
    for(int i = 0; i < 5; i++)
    {
        if(s[i] != t[i])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}