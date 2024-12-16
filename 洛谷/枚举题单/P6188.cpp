#include <bits/stdc++.h>
using namespace std;
int main()
{
    //7 4 3
    int n;
    cin >> n;
    if(n == 0)//注意特判, n为0也算刚刚好用完
    {
        cout << "0 0 0" << "\n";
        return 0;
    }
    for(int p = n / 14; p >= 0; p--)
    {
        for(int j = p; j <= n/4; j++)//枚举b
        {
            for(int k = p; k <= n; k++)//枚举c
            {
                if(p*7 + j*4 + k*3 == n)//如果有解
                {
                    cout << p << " " << j << " " << k << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "-1\n";
    return 0;
}