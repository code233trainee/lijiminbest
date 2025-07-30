// https://codeforces.com/problemset/problem/2056/A
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if(i == 0)
        {
            sum += m*4;
        }
        else
        {
            sum += (x + y)*2;
        }
    }
    cout << sum << endl;
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