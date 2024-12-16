#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(auto &z : a)
    {
        cout << z << " ";
    }
    cout << "\n";
    return 0;
}