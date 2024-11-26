#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a*b) > (c*d) ? "gzy" : ((a*b) == (c*d)) ? "gzy" : "lz") << endl;
}