#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int a = s.find('A');
    int b = s.find('B');
    int c = s.find('C');
    if(a != string::npos && b != string::npos && c != string::npos)
    {
        cout << "Yes" << "\n";
    }
    else
    {
        cout << "No" << "\n";
    }
}