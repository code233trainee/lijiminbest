#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    int i = 1;
    for(i = 1; k*i <= n; i++)
    {
        a[k*i] = i;
    }
    int j = 1;
    while(i <= n)
    {
        if(a[j] == 0)
        {
            a[j] = i;
            j++;
            i++;
        }
        else
        {
            j++;
        }
        
    }
    for(int k = 1; k <= n; k++)
    {
        cout << a[k] << " \n"[k == n];
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}