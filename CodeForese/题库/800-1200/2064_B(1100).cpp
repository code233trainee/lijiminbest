#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, int> ma;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    int l = 0;
    int mxlen = 0;
    //同种元素只会增加答案不会对答案产生影响
    for(int i = 1; i <= n; i++)
    {
        if(ma[a[i]] == 1)
        {
            int len = 1;
            while(i + len <= n && ma[a[i+len]] == 1)
            {
                len++;
            }
            if(mxlen < len)
            {
                mxlen = len;
                l = i;
            }
            i = i + len;
        }
    }
    if(l == 0)
    {
        cout << "0\n";
        return;
    }
    cout << l << " " << l + mxlen - 1 << endl;
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