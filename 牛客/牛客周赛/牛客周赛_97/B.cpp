#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 1;
    while(n)
    {
        int k = n % 10;
        n /= 10;
        sum *= k;
    }
    int temp = sqrt(sum);
    if(temp * temp == sum)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}