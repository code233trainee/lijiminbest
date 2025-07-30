#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, x;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    for(auto z : a)
    {
        if(z == x)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;

}