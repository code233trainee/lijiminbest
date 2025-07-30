#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    if(n % 4 == 0)
    {
        cout << "Bob" << endl;
    }
    else
    {
        cout << "Alice" << endl;
    }
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