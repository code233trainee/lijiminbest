#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define long double double;
int main()
{
    double lixi = 0.00005;
    int n;
    cin >> n;
    double total = 0.00;
    for(int i = 0; i < n; i++)
    {
        double mon;
        cin >> mon;
        double c = floor(lixi * 100 * total + 1e-8) / 100;
        if(c < 0.01)
        {
            c = 0;
        }
        total = total + mon + c;
        cout << fixed << setprecision(2) << floor((total + 1e-8) * 100) / 100 << endl;
    }
    return 0;
}