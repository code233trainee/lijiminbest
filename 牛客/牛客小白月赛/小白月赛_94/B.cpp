#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int j = 2;
    for(; j <= n; j++)
    {
        if(a[j] < a[1])
        {
            cout << n << "\n";
            return;
        }
    }
    cout << "0\n";

}   
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}