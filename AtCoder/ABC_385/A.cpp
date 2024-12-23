#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> ma;
    ma[a]++, ma[b]++, ma[c]++;
    if(ma.size() == 1)
    {
        cout << "Yes\n";
        return 0;
    }
    if(ma.size() == 2)
    {
        cout << "No\n";
        return 0;
    }
    if(a + b == c || a + c == b || b + c == a)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}