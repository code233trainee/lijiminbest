#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<string> v(n);
    for(int i = 0; i < n; i++)
    {
        
        cin >> v[i];
        
    }
    for(int i = 0; i < n; i += k)
    {
        for(int j = 0; j < n; j += k)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}