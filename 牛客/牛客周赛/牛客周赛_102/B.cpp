#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> dis;
    for(int i = 0; i < n; i++)
    {   
        if(s[i] == '1')
        {
            dis.push_back(i);
        }
    }
    if(dis[1] - dis[0] == dis[2] - dis[1])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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