#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, n;
    cin >> a >> b >> n;
    long long total = a*5 + b*2;
    long long s1 = n % total;
    long long s2 = n / total;
    if(s1 <= a*5)
    {
        cout << s2*7 + (s1 + (a - 1)) / a;
    }
    else
    {
        cout << s2*7 + 5 + (s1 - 5*a + (b-1)) / b;
    }
    return 0;
}