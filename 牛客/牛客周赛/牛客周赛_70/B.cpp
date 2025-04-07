#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, k, t;
    char c;
    cin >> x >> y >> k >> t >> c;
    if(c == 'G')
    {
        if(k < t)
        {
            cout << k + t + x << endl;
        }
        else
        {
            cout << t << endl;
        }
    }
    else
    {
        cout << k + t << endl;
    }

}