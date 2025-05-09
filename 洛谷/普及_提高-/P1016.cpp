#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << fixed << setprecision(2);
    double dis, C, dis2, P;
    int n;
    cin >> dis >> C >> dis2 >> P >> n;
    double ans = 0;
    // if(n == 0)
    // {
    //     double price = dis / dis2 * P;
    //     if(price / P > C)
    //     {
    //         cout << "No Solution" << endl;
    //     }
    //     else
    //     {
    //         cout << price << endl;
    //     }
    //     return 0;
    // }
    vector<pair<double, double>> a(10);
    for(int i = 1; i <= n; i++)
    {
        double p, d;
        cin >> d >> p;
        a[i] = {d, p};
    }
    a[n+1].first = dis;
    a[0].second = P;
    for(int i = 1; i <= n; i++)
    {
        if(a[i+1].first - a[i].first > C*dis2)
        {
            cout << "No Solution" << endl;
            return 0;
        }
    }
    int j;
    double last;
    for(int i = 0; i <= n; i = j)
    {
        for(j = i + 1; j <= n+1; j++)
        {
            if(a[j].first-a[i].first > C * dis2)
            {
                j--;
                break;
            }
            if(a[j].second < a[i].second)
            {
                break;
            }
        }
        if(a[j].second < a[i].second)
        {
            ans += ((a[j].first - a[i].first) / dis2 - last) * a[i].second;
            last = 0;
        }
        else
        {
            ans += (C - last) * a[i].second;
            last = C - (a[j].first - a[i].first) / dis2;
        }
    }
    cout << ans << endl;
    return 0;
}