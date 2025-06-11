#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, s;
    cin >> n >> s;
    int last = 0;
    while(n--)
    {
        int t;
        cin >> t;
        if(t - last > s)
        {
            cout << "No\n";
            return 0;
        }
        last = t;
    }
    cout << "Yes\n";
    return 0;
}