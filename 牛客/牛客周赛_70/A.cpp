#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (a == b && a == c && a == d ? "NO" : "YES") << endl;
    }
    
}