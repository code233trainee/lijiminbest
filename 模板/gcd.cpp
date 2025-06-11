#include <iostream>
using ll = long long;
//求最大公约数
//两个数的积等于它们最大公约数和它们最小公倍数的积
//a*b=gcd(a,b)*lcm(a,b)
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//返回最小的质因数
ll get(ll n) {
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}
int main()
{

}