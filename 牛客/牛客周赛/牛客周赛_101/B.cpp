#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = 2 * (n / 5);
    int y = 1;
    if(n < 5)
    {
        y = 0;
    }
    else
    {
        y += (n-5) / 10;
    }
    int z = 3*(n / 20);
    int g = 2*n - (z/3)*2;
    cout << x << " " << y << " " << z << " " << g << endl;
    return 0;
}