#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> pre(n+1);
    vector<bool> loc(n); 
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pre[i+1] = pre[i] + a[i]; 

        if(a[i] >= m)
        {
            loc[i] = true;
        }
    }
    if(pre[n] < m)
    {
        cout << "-1\n";
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(loc[i]) continue;
            
        }
    }
    return 0;
}