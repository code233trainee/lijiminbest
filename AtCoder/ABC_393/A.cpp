#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if(s1 == "sick" && s2 == "sick")
    {
        cout << "1\n";
    }
    else if(s1 == "sick" && s2 == "fine")
    {
        cout << "2\n";
    }
    else if(s1 == "fine" && s2 == "sick")
    {
        cout << "3\n";
    }
    else
    {
        cout << "4\n";
    }
    return 0;
}