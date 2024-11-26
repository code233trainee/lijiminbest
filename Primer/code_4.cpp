#include <string>
#include <iostream>
#include "Sales_item.h"
double applyDiscount(double,double)
{
  return 0.16;
}

std::string galobal_int="";
int galobal_str=0;


int main()
{
    unsigned u=10;
    int a=42;
    std::cout<<u-a<<"\n";//int类型被转化成无符号类型unsigned
    //无符号数的负数输出结果需要视在当前机器上int所占位数而定


    std::cout<<'\n';//\n换行可以用单引号或者双引号，但如果插在字符中间不用再单独用引号
    std::cout<<"\tHi!\n";
    std::cout<<"Hi! \x4do\115!\n";//（\x4d）与（\115）代表字符M
    std::cout<<'\115'<<'\n';


    double price=109.99,discount=price*0.16;//price先被定义赋值，随后被用于初始化discount
    double salePrice = applyDiscount(price,discount);//调用函数，并用函数的返回值初始化salePrice
    std::cout<<salePrice<<'\n';


    long double ld=3.1415926536;
    int e{(int)ld},b={(int)ld};//花括号初始化不允许隐式类型转换
    int c(ld),d=ld;
    std::cout<<c<<" "<<d;

    int local_int=0;
    std::string local_str="";
    std::cout<<"   is:"<<galobal_int<<galobal_str<<local_int<<local_str;    
    }
