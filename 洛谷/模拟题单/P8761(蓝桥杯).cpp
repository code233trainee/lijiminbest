#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            //大写字母要比小写字母的ascii码小
            s[i] = s[i] - 32;
        }
    }
    cout << s;
    return 0;
}