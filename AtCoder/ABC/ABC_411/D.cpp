#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    string ans = "";
    unordered_map<int, string> ma;
    while(q--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int y;
            cin >> y;
            ma[y] = ans;
        }
        else if(x == 2)
        {
            int y;
            string t;
            cin >> y >> t;
            ma[y] += t;
        }
        else
        {
            int y;
            cin >> y;
            ans = ma[y];
        }
    }
    cout << ans << endl;
    return 0;
}