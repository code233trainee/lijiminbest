#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt0 = 3, cnt1 = 1, cnt2 = 2, cnt3 = 1, cnt5 = 1;
    for(int i = 0; i < n; i++)
    {
        switch(a[i])
        {
            case 0: cnt0--; break;
            case 1: cnt1--; break;
            case 2: cnt2--; break;
            case 3: cnt3--; break;
            case 5: cnt5--; break;
        };
        if(cnt0<=0 && cnt1<=0 && cnt2<=0 && cnt3<=0 && cnt5<=0)
        {
            cout << i+1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
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