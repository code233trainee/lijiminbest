#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    s = "$" + s;
    for(int i = l; i <= r; i++)
    {
        if(s[i] == 'x')
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}