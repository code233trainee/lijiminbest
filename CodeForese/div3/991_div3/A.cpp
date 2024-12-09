#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int length = 0;
    vector<string> vs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> vs[i];
    }
    for(int i = 0; i < n; i++)
    {
        length += vs[i].length();
        if(length <= m)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    cout << ans << "\n";
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}