#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for(int i = 0; i < n - m + 1; i++)
    {
        int temp = 0;
        for(int j = i; j < m + i; j++)
        {
            temp += a[j];
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}