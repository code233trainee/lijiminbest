#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    double s, a, b;
    cin >> s >> a >> b;
    double x = (b + a) * s / (b + 3*a);
    double ans = x/b + (s - x) / a;
    cout << fixed << setprecision(6) << ans;
    return 0;
}