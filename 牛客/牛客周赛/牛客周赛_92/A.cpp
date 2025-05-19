#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    s = "a_";
    for(int i = 2; i < n; i++)
    {
        s += "b";
    }
    cout << s;
    return 0;
}