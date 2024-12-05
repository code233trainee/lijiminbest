#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        ll r, c, r0, c0;
        cin >> r >> c >> r0 >> c0;
        ll totalR = r - r0;
        ll elementR = c - c0; 
        ll totalC = totalR * (c - 1);
        totalR *= c;
        ll total = totalC + totalR + elementR;
        cout << total << endl;
    }
}