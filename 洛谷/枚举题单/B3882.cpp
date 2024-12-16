#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    std::cin >> n;
    vector<string> a;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        a.push_back(to_string(i));
    }
    for(int i = 0; i < n; i++)
    {
        int r = a[i].length() - 1;
        bool ok = true;
        for(int j = 0; j <= r;)
        {
            if(a[i][j] != a[i][r])
            {
                ok = false;
                break;
            }
            j++;
            r--;
        }
        if(ok)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}