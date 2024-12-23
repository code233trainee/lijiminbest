#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double total = 0.0;
    while(n--)
    {
        double a, b;
        cin >> a >> b;
        total += a * b;
    }
    total *= 0.85;
    cout << std::fixed << std::setprecision(1) << floor((total * 10)) / 10.0 << "\n";
    return 0;
}