#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 0; i < n; i++)
    {
        int res = 1;
        while(i < n - 1)
        {
            if(a[i] + 1 == a[i+1])
            {
                res++;
                i++;
            }
            else
            {
                break;
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}