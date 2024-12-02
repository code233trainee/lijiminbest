#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d;
    string s;
    cin >> n >> d >> s;
    int cook = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '@')
        {
            cook++;
        }
    }
    cout << (n - cook) + d << endl;
    return 0;
}