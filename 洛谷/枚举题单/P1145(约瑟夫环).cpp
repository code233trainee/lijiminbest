#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int m = k;
    int flag = 1;
    while(flag)
    {
        m++;
        int cursor = 0;
        for(int i = 0; i < k; i++)
        {
            cursor = (cursor + m - 1) % (2 * k - i);
            if(cursor < k)
            {
                break;
            }
            if(i == k - 1)
            {
                flag = 0;
            }
        }
    }
    cout << m;
    return 0;
}