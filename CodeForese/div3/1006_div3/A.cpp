#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    if(k < 0)
    {
        k = -k;
    }
    if(n * p < k)
    {
        cout << "-1\n";
        return;
    }
    if(k % p)
    {
        cout << k / p + 1 << "\n"; 
    }
    else
    {
        cout << k / p<< "\n";
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
    return 0;
}