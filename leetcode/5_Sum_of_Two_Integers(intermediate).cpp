//给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
#include <iostream>
int getSum(int a, int b) {
        int sum,carry;//异或(^)相同为1，不同为0
        sum=a^b;//将两个数按位异或(无进位的加法)
        carry=(a&b)<<1;//按位与(&)
        if(carry!=0)//判断是否还有进位，有则再次返回这两个数
        {
            return getSum(sum,carry);
        }
        return sum;
    }
int main()
{
    std::cout<<getSum(-1,-3);
}