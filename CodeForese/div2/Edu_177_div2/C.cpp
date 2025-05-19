#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n+1), d(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    set<int> X;
    for(int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;
        while(!X.count(d))
        {
            X.insert(d);
            d = p[d];
        }
        cout << X.size() << " ";
    }
    cout << endl;
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