#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // while(a.size() > 1)
    // {
    //     int sum = a[0] + a[1] - 1;
    //     a.erase(a.begin(), a.begin() + 2);
    //     a.push_back(sum);
    // }
    for(int i = 0; i < a.size() - 1; i += 2)
    {
        int sum = a[i] + a[i+1] - 1;
        a.push_back(sum);
    }
    cout << a.back() << "\n";
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