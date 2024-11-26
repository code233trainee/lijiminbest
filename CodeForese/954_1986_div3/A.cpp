#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> v(3);
        for(auto &z : v)
        {
            cin >> z;
        }
        sort(v.begin(), v.end());
        
        int ans = 0;
        ans += abs(v[0] - v[1]);
        ans += abs(v[1] - v[2]);
        cout << ans << endl;
    }
}