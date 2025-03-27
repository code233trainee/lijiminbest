#include <iostream>
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

int main()
{

}