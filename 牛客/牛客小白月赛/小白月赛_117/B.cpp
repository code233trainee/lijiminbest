#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    int cnt1 = 0, cnt0 = 0, cntL1 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if(a[i] == 0)
        {
            cnt0++;
        }
        if(a[i] == 1)
        {
            cnt1++;
        }
    }
    cntL1 = n - cnt1 - cnt0;
    if(cnt0 == n || cnt1 == cntL1 || (cnt1 > cntL1 && cntL1 != 0) || (cntL1 > cnt1 && cnt1 != 0))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    
    return 0;
}