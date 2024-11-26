#include <bits/stdc++.h>
using namespace std;

int jump(int n, int d)
{
    int temp = n / d;
    if( (n % d) )
    {
        return ++temp;
    }
    else
    {
        return temp;
    }
}

void solve(int x, int y, int d)
{
    int a = jump(x, d);
    int b = jump(y, d);
    if(a == b)
    {
        cout << a + b << "\n";
    }
    else if(a > b)
    {
        cout << 2 * a - 1 << "\n";
    }
    else
    {
        cout << 2 * b << "\n";
    }
}

int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        int x, y, d;
        cin >> x >> y >> d;
        solve(x, y, d);
    }
}