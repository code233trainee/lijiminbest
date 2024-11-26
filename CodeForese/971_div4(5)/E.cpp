#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// const int MAX = 1e9 + 5;
// int a[MAX], nums[MAX];

ll Eplus(ll a, ll b)
{
    ll total = 0;
    for(int i = b; i <= a + b - 1; i++ )
    {
        total += i;
    }
    return total;
}

void minimum(ll a, ll b)
{
    ll total = Eplus(a, b);
    ll plus = 0, increas = 0;

    ll k = 0, c = 0; 

    for(ll j = b; j <= a + b - 1; j++)
    {
        plus += j;
        increas = total - plus;
        k = plus - increas;
        if(abs(c) < k)
        {
            cout << abs(c) << endl;
            break;
        }
        c = k;
    }
}



// void mini(int a, int b)
// {

//     for(int i = b; i <= b + a - 1; i++)
//     {

//     }
// }

int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        ll a, b;
        cin >> a >> b;
        // if(a % 2)
        // {
        //     i = a / 2 + 1;
        // }
        // else
        // {
        //     i = a / 2;
        // }
        minimum(a, b);
    }
}