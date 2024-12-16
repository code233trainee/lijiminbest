#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> y(n);
    int x;
    for(auto &z : y)
    {
        cin >> x >> z;
    }
    sort(y.begin(), y.end());
    long long ans = INT_MAX;
    for(int i = y[0]; i < y[n-1]; i++)
    {
        long long temp = 0;
        for(int j = 0; j < n; j++)
        {
            temp += abs(i - y[j]);
        }
        ans = min(ans, temp);
    }
    cout << ans;
    return 0;
}