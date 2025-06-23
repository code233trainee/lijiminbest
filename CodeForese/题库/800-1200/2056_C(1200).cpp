// https://codeforces.com/problemset/problem/2056/C
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    if(n == 6)
    {
        cout << "1 1 2 3 1 2" << endl;
    } 
    else
    {
        for(int i = 1; i <= n - 2; i++)
        {
            cout << i << " ";
        }
        cout << "1 2" << endl;
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