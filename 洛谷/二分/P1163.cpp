#include <bits/stdc++.h>
using namespace std;
double n, m, k;
bool pf(double x)
{
    return (pow(1.0/(1.0+x), k) >= 1-n/m*x);
}
int main()
{
    cin >> n >> m >> k;
    double l = 0, r = 10;
    while(r - l >= 0.0001)
    {
        double mid = (l + r) / 2;
        if(pf(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << fixed << setprecision(1) << l * 100;
    return 0;
}