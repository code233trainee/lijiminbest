#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "$" + s;
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++)
    {
        pre[i] = pre[i-1] + (s[i] == '1');
    }
    int ans = INT_MAX;
    // 注意不能等于n，因为是分为四段的
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                int cost1 = 0, cost0 = 0;

                int A1 = i - pre[i], A0 = pre[i];
                int B1 = j - i - (pre[j] - pre[i]), B0 = pre[j] - pre[i];
                int C1 = k - j - (pre[k] - pre[j]), C0 = pre[k] - pre[j];
                int D1 = n - k - (pre[n] - pre[k]), D0 = pre[n] - pre[k];

                cost1 = A1 + B0 + C1 + D0;
                cost0 = A0 + B1 + C0 + D1;
                ans = min(ans, min(cost1, cost0));
            }
        }
    }

    cout << ans << endl;
    return 0;
}