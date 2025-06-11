#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    int n = max(a, b);
    for(int i = 2; i <= n; i++)
    {
        if(gcd(i, a) == 1 && gcd(i, b) == 1)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
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