#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mx = INT_MIN;
    int mn = INT_MAX;
    double total = 0;
    double n = 0;
    cin >> n;
    int temp = n;
    while(temp--)
    {
        int sorc;
        cin >> sorc;
        total += sorc;
        if(sorc > mx)
        {
            mx = sorc;
        }
        if(sorc < mn)
        {
            mn = sorc;
        }
    }
    double ave = total/n;
    cout << mx << "\n";
    cout << mn << "\n";
    cout << std::fixed << std::setprecision(2) << ave << "\n";
    return 0;
}