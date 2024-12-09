#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    for(int i = 0; i < n; i++)
    {
        cin >> xy[i].first >> xy[i].second;
    }
    double ans = 20000000;
    for(int i = 0; i < n; i++)
    {
        double rr = 0;
        for(int j = 0; j < n; j++)
        {
            double r = sqrt((xy[i].first - xy[j].first)*(xy[i].first - xy[j].first) + (xy[i].second - xy[j].second)*(xy[i].second - xy[j].second));
            rr = max(rr, r);
        }
        ans = min(ans, rr);
    }
    
    cout << std::fixed << std::setprecision(4) << pi * ans * ans << endl;
    return 0;
}