#include <iostream>
using ll = long long;
//求最大公约数
//两个数的积等于它们最大公约数和它们最小公倍数的积
//a*b=gcd(a,b)*lcm(a,b)

// 要对n个数求LCM，就要对每个质因子单独取最高幂次，
// 再把它们全部乘起来——这也是我们用质因数分解来记录“最大指数”并重建结果的原因。
// 这样才能保证所有数都能被整除，且结果最小。
// 例题2025省赛马蹄杯第一场Q6
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