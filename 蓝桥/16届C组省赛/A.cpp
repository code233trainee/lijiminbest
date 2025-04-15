#include <bits/stdc++.h>
using namespace std;
bool check(int a)
{
    int count = 0;
    while(a)
    {
        int b = a%10;
        a /= 10;
        count += b;
    }
    if(count % 5 == 0)
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
    int cnt = 0;
    for(int i = 1; i <= 202504; i++)
    {
        if(check(i))
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}