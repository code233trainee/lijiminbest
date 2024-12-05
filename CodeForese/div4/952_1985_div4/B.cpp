#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    //只有n=3时是例外，其他数字均是x=2时最大
    cout << (n == 3 ? 3 : 2) << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}