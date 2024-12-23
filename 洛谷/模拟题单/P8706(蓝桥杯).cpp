#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    string a = "";
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
        {
            a += s[i];
        }
        else
        {
            int b = s[i] - '0';
            //构造特定数量的字符串
            string temp(b-1, s[i-1]);
            a += temp;
        }
    }
    cout << a << "\n";
    return 0;
}