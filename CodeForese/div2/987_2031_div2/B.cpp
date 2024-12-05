#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &z : v)
    {
        cin >> z;
    }
    for(int i = 0; i < n - 1; i++)
    {
        if(v[i] != i + 1)
        {
            if(v[i+1] == i+1 && v[i] == i + 2)
            {
                swap(v[i], v[i+1]);
            }
            else
            {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}