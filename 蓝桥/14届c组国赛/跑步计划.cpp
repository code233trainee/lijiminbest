#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    //能被4整除但是不能被100整除，或者能被400整除
    // if((2023%4==0 && 2023%100!=0) || (2023%400==0))
    // {
    //     cout << "yes";
    // }
    // else
    // {
    //     cout << "no";
    // }
    // 2023不是闰年
    ll ans = 0;
    int k = 6;
    ll a[] ={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1; i <= 12; i++)
    {
        for(int j = 1; j <= a[i]; j++)
        {
            k++;
            if(i == 1 || i == 10 || i == 11 || i == 12)
            {
                ans += 5;
                continue;
            }
            if(j % 10 == 1 || j / 10 % 10 == 1 || k % 7 == 1)
            {
                ans += 5;
            }
            else
            {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}