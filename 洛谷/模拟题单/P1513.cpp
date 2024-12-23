#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926;
int main()
{
    int n;
    double r;
    cin >> n >> r;
    vector<double> x(n);
    vector<double> y(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    if(n==1)
    {
        cout << std::fixed << std::setprecision(2) << 2*pi*r << "\n";
        return 0;
    }
    double dis = 0.0;
    for(int i = 0; i < n-1; i++)
    {
        dis += sqrt(((x[i] - x[i+1])*(x[i] - x[i+1])) + ((y[i] - y[i+1])*(y[i] - y[i+1])));
    }
    dis += sqrt(((x[0] - x[n-1])*(x[0] - x[n-1])) + ((y[0] - y[n-1])*(y[0] - y[n-1])));
    dis += 2 * pi * r;
    cout << std::fixed << std::setprecision(2) << dis << "\n";
    return 0;
}