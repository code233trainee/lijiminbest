#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct ty{
    int val, pos;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> ma;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    //注意，没有满足条件的需要输出-1
    ll ans = -1;
    for(int i = 0; i < n; i++)
    {
        if(ma[a[i]] == 1)
        {
            if(ans == -1 || a[i] > a[ans - 1])
            {
                ans = i + 1;
            }
        }
    }   
    cout << ans<< "\n";
    return 0;
}