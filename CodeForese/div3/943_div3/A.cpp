#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//注意，题目给的是gcd(x, y) + y;
//而y < x
//对于 x≥y
//结果是 gcd(x,y)=gcd(x−y,y)
//利用 gcd(x−y,y)≤x−y
//的事实，我们得到 gcd(x−y,y)+y≤x−y+y=x
//因此，对于 1≤y<x
//结果是 gcd(x,y)+y≤x
void solve()
{
    int x;
    cin >> x;
    int max = -100;
    int y = 0;
    for(int i = x-1; i >= 1; i--)
    {
        int temp = gcd(i, x) + i;
        if(temp > max)
        {
            max = temp;
            y = i;
        }
    }
    cout << y << endl;
}
//下面是题解
// cin >> x;
// cout << x-1 << endl;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}