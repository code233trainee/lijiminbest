#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> pos;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            pos.push_back(i);
        }
    }
    if(pos.empty())
    {
        cout << "YES\n";
        return;
    }
    if(n <= 2)
    {
        cout << "NO\n";
    }
    else
    {
        if(pos.size() == 1 || pos.back() == (n-1))
        {
            cout << "NO\n";
        }
        else if(pos[0] + 1 == pos[1])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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