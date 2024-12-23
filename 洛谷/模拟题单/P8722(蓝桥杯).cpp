#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> a = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string s;
    cin >> s;
    string temp = s.substr(0, 3);
    for(int i = 1; i <= 12; i++)
    {
        if(a[i] == temp)
        {
            cout << i << " ";
        }
    }
    int b = s[3] - '0';
    int d = s[4] - '0';
    int day = b * 10 + d;
    cout << day;
    return 0;
}