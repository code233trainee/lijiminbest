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
void solve()
{
    int x, y;
    cin >> x >> y;
    int g = gcd(x, y);
    if(x + y > g && x + g > y && y + g > x)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}