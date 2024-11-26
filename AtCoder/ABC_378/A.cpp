#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, int> m;
    for(int i = 0; i < 4; i++)
    {
        int num;
        cin >> num;
        m[num]++;
    }
    int ans = 0;
    for(auto z : m)
    {
        ans += z.second/2;
    }
    cout << ans << endl;
    return 0;
}