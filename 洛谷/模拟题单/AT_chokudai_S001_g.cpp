#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
// long long quickPower(long long a,long long b)
// {
//     long long ans=1;
//     a=a%mod;
//     while(b>0)
//     {
//         if(b%2==1) ans=(ans*a)%mod;
//         b/=2;
//         a=(a*a)%mod;
//     }
//     return ans;
// }
ll quickPower(ll a, ll b)//是求a的b次方
{
	ll ans = 1, base = a;//ans为答案，base为a^(2^n)
	while(b > 0)//b是一个变化的二进制数，如果还没有用完
    {
		if(b & 1)//&是位运算，b&1表示b在二进制下最后一位是不是1，如果是：
        {
            ans = (ans*base) % mod;//把ans乘上对应的a^(2^n)
        }
        base = (base*base) % mod;//base自乘，由a^(2^n)变成a^(2^(n+1))
		b >>= 1;//位运算，b右移一位，如101变成10（把最右边的1移掉了），10010变成1001。现在b在二进制下最后一位是刚刚的倒数第二位。结合上面b & 1食用更佳
	}
	return ans;
}
int main()
{
    int n;
    cin >> n;
    string s = "";
    for(int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        s += a;
    }
    ll ans = 0;
    int len = s.length();
    for(int i = len - 1; i >= 0; i--)
    {
        ans += 1ll*(s[i]-'0')*(quickPower(10, len-i-1));
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}