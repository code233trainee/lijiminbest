#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<double, double> a, pair<double, double> b)
{
    return a.first/a.second < b.first/b.second;
}
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<double, double>> vp;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(gcd(i, j) == 1 && j >= i)
            {
                vp.push_back({i, j});
            }
        }
    }
    sort(vp.begin(), vp.end(), cmp);
    for(int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << '/' << vp[i].second << endl;
    }
    return 0;
}