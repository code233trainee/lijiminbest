#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) 
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);    

    ll n, h;
    cin >> n >> h;
    for(ll i = 0; i < n; i++)
    {
        //向量方向，这个水面问题，我们只需要找到对应的z就可以了
        //然后用gcd，使得gcd(x,y,z) = 1
        //gcd(x,y,z) = 1,
        //g = gcd(x,y)
        //g = gcd(g,z)
        //这两步是为了找到它们的最大公约数，然后将它们全部除以g，即可得出结果

        //在这个问题中我们并不关心实际上的与水面的反射点，我们只需要求出方向向量即可
        ll x, y, z;
        cin >> x >> y >> z;
        ll h1 = (2 * h) - z;
        ll g = 0;
        g = gcd(x, y);
        g = gcd(g, h1);
        x /= g;
        y /= g;
        h1 /= g;
        cout << x << " " << y << " " << h1 << "\n";
    }
    

}