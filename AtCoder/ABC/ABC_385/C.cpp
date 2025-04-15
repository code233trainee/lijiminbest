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
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            for(int k = j, lst = -1, num = 0; k < n; k += i)
            {
                if(a[k] == lst)
                {
                    num++;
                    ans = max(ans, num);
                }
                else
                {
                    lst = a[k];
                    num = 1;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}