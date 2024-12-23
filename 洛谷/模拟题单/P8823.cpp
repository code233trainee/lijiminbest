#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n >= 90)
    {
        cout << "4.0\n";
    }
    if(n >= 60 && n <= 89)
    {
        double a = 4.0;
        a -= (90 - n) * 0.1;
        cout << std::fixed << std::setprecision(1) << a << "\n"; 
    }
    if(n < 60)
    {
        n = sqrt(n) * 10;
        if(n >= 60)
        {
            double a = 4.0;
            a -= (90 - n) * 0.1;
            cout << std::fixed << std::setprecision(1) << a << "\n";
        }
        else
        {
            cout << "0.0\n";
        }
    }
    return 0;
}