#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    // for(int i = 1; i < 1001; i++)
    // {
    //     int k = i, m = i;
    //     ll a = 1, b = 1;
    //     while(k > 1)
    //     {
    //         a += k;
    //         k--;
    //     }
    //     while(m)
    //     {
    //         b *= m;
    //         m--;
    //     }
    //     if((a - b) % 100 == 0)
    //     {
    //         cout << i << " ";
    //     }
    // }
     
    // 打表找规律
    ll c = 2024041331404202;
    cout << (c / 200 - 1) * 4  + 5 + 1;
    return 0;
}