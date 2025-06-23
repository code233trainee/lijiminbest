#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> ma;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(ma[x-1] >= 1)
        {
            ma[x-1]--;
            ans++;
            continue;
        }
        ma[x]++;
    }
    cout << ans << endl;
    return 0;
}