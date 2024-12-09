#include <bits/stdc++.h>
int main()
{
    double num = 3.1415926;
    std::cout << std::fixed << std::setprecision(4) << num << std::endl;
    //单独使用std::setprecision(4)就是保留四位有效数字(包括整数部分)
    //使用fixed和std::setprecision(4)就指定了保留小数点后四位(不足补零),是四舍五入
}