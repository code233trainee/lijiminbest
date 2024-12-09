#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int num = 0;
    for(double i = -100.00; i <= 100.00; i+= 0.001)
    {
        double l = i;
        double r = i + 0.001;
        if((a*l*l*l + b*l*l + c*l + d)*(a*r*r*r + b*r*r + c*r + d) < 0)
        {
            cout << std::fixed << std::setprecision(2) << l << " ";
            num++;
        }
        if(num == 3)
        {
            break;
        }
    }
    return 0;
}