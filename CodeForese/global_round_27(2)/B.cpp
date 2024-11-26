#include <bits/stdc++.h>
using namespace std;
//主要找到最小的偶数和奇数(最小后缀)
int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        int a = 0;
        cin >> a;
        if(a == 1 || a == 3)
        {
            cout << "-1" << endl;
            continue;
        }
        if(a % 2)
        {
            a -= 5;
            string s(a, '3');
            s += "36366";
            cout << s << endl;
        }
        else
        {
            a -= 2;
            string s2(a, '3');
            s2 += "66";
            cout << s2 << endl;
        }
    }
    return 0;
}