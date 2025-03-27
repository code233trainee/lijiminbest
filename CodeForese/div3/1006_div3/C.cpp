#include <bits/stdc++.h>
using namespace std;
void solve()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    int sum = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        if((i | x) == x)
        {
            a[i] = i;
            sum |= i;
        }
        else
        {
            break;
        }
    }
    if(sum != x)
    {
        a[n-1] = x;
    }
    for(auto z : a)
    {
        cout << z << " ";
    }
    cout << "\n";
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