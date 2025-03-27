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
    // xor and
    // xor gcd (排除)
    // and xor
    // and gcd (排除)
    // gcd and
    // gcd xor
    int x, y;
    cin >> x >> y;
    
    if((x & y) == 0 || (x ^ y) == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        auto check = [&](int x, int y) -> bool{
            int XOR = x ^ y, AND = x & y, GCD = gcd(x, y);
            if((XOR & x) == 0 || (XOR & y) == 0) return 1;
            if((AND ^ x) == 0 || (AND ^ y) == 0) return 1;
            if((GCD & x) == 0 || (GCD & y) == 0) return 1;
            if((GCD ^ x) == 0 || (GCD ^ y) == 0) return 1;
            return 0;
        };
        cout << 3 - check(x, y) << endl;
    }

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