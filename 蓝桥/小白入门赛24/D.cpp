#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll check(ll n)
{
    ll result = n;
    for(ll i = 2; i < sqrt(n); i++)
    {
        if(n%i == 0)
        {
            result -= result / i;
            while(n % i == 0)
            {
                n /= i;
            }
        } 
    }
    if(n > 1)
    {
        result -= result / n;
    }
    return result;
}
int main()
{
    ll n;
    cin >> n;
    cout << check(n) << "\n";
    return 0;
}