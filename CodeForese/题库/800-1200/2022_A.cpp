#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    int alone = 0;
    int happy = 0;
    for(auto z : a)
    {
        cin >> z;
        happy += (z/2) * 2;
        r -= z/2;
        alone += z%2;
    }
    if(alone > r)
    {
        happy += r * 2 - alone;
    }
    else
    {
        happy += alone;
    }
    cout << happy << "\n";
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