#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for(int i = 1; i < n; i++)
    {
        cin >> c[i];
    }
    for(int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    int pre = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i])
        {
            int l = i;
            int r = i;
            while(pre < l)
            {
                res++;
                int nl = l;
                for(int j = l; j <= r; j++)
                {
                    nl = min(nl, j - c[j]);
                }
                l = nl;
            }
            pre = i;
            
        }
    }
    cout << res << "\n";
    return 0;
}