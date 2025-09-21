#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x % 2)
        {
            a.push_back(x);
        }
        else
        {
            b.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i =0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    for(int i =0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}