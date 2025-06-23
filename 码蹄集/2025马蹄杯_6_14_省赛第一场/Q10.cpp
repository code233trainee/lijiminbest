#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int, greater<int>> ma;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ma[x]++;
    }
    for(auto z : ma)
    {
        cout << z.first << " ";
    }
    return 0;
}