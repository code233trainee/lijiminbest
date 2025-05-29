#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if((a[0] + a[n-1]) % 2 == 0)
    {
        cout << "0\n";
        return;
    }
    int pe = 0, po = 0;
    int se = 0, so = 0;
    for(int i = 0; i < n; i++)
    {   
        if(a[i] % 2 == 0)
        {
            if(!pe)
            {
                pe = i;
            }
        }
        else
        {
            if(!po)
            {
                po = i;
            }
        }
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] % 2 == 0)
        {
            if(!se)
            {
                se = (n - i) - 1;
            }
        }
        else
        {
            if(!so)
            {
                so = (n - i) - 1;
            }
        }
    }
    
    if(a[0] % 2 == 0)
    {
        cout << min(po, se) << endl;
    }
    else
    {
        cout << min(pe, so) << endl;
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