#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> ans(n+1);
    int R = n;
    while(R > 0)
    {
        int bit = -1;
        for(int j = 20; j >= 0; j--)
        {
            if(R >> j & 1)
            {
                bit = j;
                break;
            }
        }
        int L = 1 << bit;
        int len = R - L + 1;
        int nR = R - 2 * len + 1;
        for(int i = nR, j = R; i < j; i++, j--)
        {
            ans[i] = j;
            ans[j] = i;
        }
        R = nR - 1;
    }
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << ans[x] << " \n"[i == n];
    }
    return 0;
}