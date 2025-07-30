#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(k == 1)
    {
        cout << "YES\n";
        return;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    //第k-1小的元素
    int cutoff = b[k-2];
    vector<int> c;
    for(auto z : a)
    {
        if(z <= cutoff)
        {
            c.push_back(z);
        }
    }
    //最多可以删除的元素个数
    int spare = c.size() - k + 1;
    int L = 0, R = c.size()-1;
    bool bad = false;
    while(L < R)
    {
        if(c[L] != c[R])
        {
            if(spare == 0)
            {
                bad = true;
                break;
            }
            if(c[L] == cutoff)
            {
                L++;
                spare--;
            }
            else if(c[R] == cutoff)
            {
                R--;
                spare--;
            }
            else
            {
                bad = true;
                break;
            }
            continue;
        }
        L++;
        R--;
    } 
    if(bad)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}