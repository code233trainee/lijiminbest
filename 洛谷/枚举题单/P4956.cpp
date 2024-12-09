#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x, k = 1;
    while(1)
    {
        for(x = 100; x >= 1; x--)
        {
            if((7*x+21*k)*52 == n)
            {
                cout << x << endl;
                cout << k << endl;
                return 0;
            }
        }
        k++;
    }
    return 0;
}