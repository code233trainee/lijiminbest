#include <bits/stdc++.h>
using namespace std;

void equal(int a, int b)
{
    if(a % 2)
    {
        cout << "NO" << endl;
    }
    else if(!(b % 2))
    {
        // if((b % 2) && (a >= 2))
        // {
        //     cout << "YES" << endl;
        //     return 0;
        // }
        // else if((b >= 2) && !(b % 2))
        // {
        //     cout << "YES" << endl;
        //     return 0;
        // }
        // else
        // {
        //     cout << "NO" << endl;
        //     return -1;
        // }
        cout << "YES" << endl;
    }
    else if((a > 0) && (b > 0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        equal(a, b);
    }
}