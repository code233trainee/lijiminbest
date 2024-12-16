#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(p+1);
    while(n--)
    {
        int c, d;
        cin >> c >> d;
        a[c] += d;
    }
    int ans = 0;
    for(int i = 1; i <= p; i++)
    {
        if(a[i] > 0)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}