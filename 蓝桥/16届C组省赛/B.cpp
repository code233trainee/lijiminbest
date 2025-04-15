#include <bits/stdc++.h>
using namespace std;
bool check(int a)
{
    int cnt0 = 0, cnt2 = 0, cnt5 = 0;
    while(a)
    {
        int b = a%10;
        a /= 10;
        if(b == 0)
        {
            cnt0++;
        }
        else if(b == 2)
        {
            cnt2++;
        }
        else if(b == 5)
        {
            cnt5++;
        }
    }
    if(cnt0 >= 1 && cnt2 >= 2 && cnt5 >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int ans = 0;
    for(int i = 1; i <= 20250412; i++)
    {
        if(check(i))
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}