#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char a, b;
    string s;
    cin >> n >> a >> b >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != a)
        {
            s[i] = b;
        }
    }
    cout << s;
    return 0;
}