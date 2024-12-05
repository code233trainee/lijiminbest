#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    if(n == 1)
    {
        cout << "1\n1" << endl;
        return;
    }
    if(k == 1 || k == n)
    {
        cout << "-1" << endl;
        return;
    }
    int p2 = k - k % 2;
    int p3 = k + 1 + k % 2;
    cout << "3\n1 " << p2 << " " << p3 << endl;
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