#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    while(n > 0)
    {
        cout << n << " ";
        n /= 2;
    }
    return 0;
}