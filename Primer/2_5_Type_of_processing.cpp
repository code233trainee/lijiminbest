#include <iostream>
#include <string>
#include "Sales_item.h"
constexpr int fun()
{
    return 42;
}
int main()
{
    //关键字typedef，用于定义类型别名 
    typedef double wages;   //wages是double的同义词
    typedef wages base,*y;  //base是wages的同义词，y是double*的同义词
    using SI=Sales_item;    //SI是Sales_item的同义词(把等号左侧的名字规定成等号右侧的类型别名)
    wages hourly,weekly;    //等价于double hourly,weekly
    SI item;                //等价于Sales_item item

    typedef char *pstring;
    const pstring cstr=0;   //cstr是指向char的常量指针(顶层const?)
    const pstring *ps;      //ps是一个指针,它的对象是指向char的常量指针
    //(const pstring)其基本数据类型是指针
    //(const char)其基本数据类型是char，*是声明符的一部分
    //const char *cstr(是对const patring cstr的错误理解)

    //auto i=0,*p=&i;         //正确：i是整数，p是整型指针(它们的初始数据类型一致)
    //auto sz=0,pi=3.14; 错误：sz和pi的类型不一致
    int i=0,&r=i;
    auto a=r;               //a是一个整数(r是i的别名，而i是一个整数)

    const int ci=i,&cr=ci;
    auto b=ci;              //b是一个整数(ci的顶层const特性别忽略掉了)
    auto c=cr;              //c是一个整数(cr是ci的别名,ci本身是一个顶层const)
    auto d=&i;              //d是一个整型指针(整数的地址就是指向整数的指针)
    const auto e=&ci;             //e是一个指向整数常量的指针(对常量对象取址是一种底层const)
    
    const auto f=ci;        //ci的推演类型是int,f是const int

    auto &g=ci;             //g是一个整型常量引用，绑定到ci
    //auto &h=42; 错误:不能用非常量引用绑定字面值
    const auto &j=42;       //正确:可以为常量引用绑定字面值
    
    auto k=ci,&l=i;         //k是整数,l是整型引用
    auto &m=ci,*p=&ci;      //m是对整型常量的引用,p是指向整型常量的指针
    //auto &n=i,*p2=&ci; 错误:i的类型是int，而&ci的类型是const int

    std::cout<<"a="<<a<<" "
             <<"b="<<b<<" "
             <<"c="<<c<<" "
             <<"d="<<d<<" "
             <<"e="<<e<<" "
             <<"g="<<g<<" "<<'\n';
    a=42;b=42;c=42;//d=42;e=42;g=42;
    std::cout<<"a="<<a<<" "
             <<"b="<<b<<" "
             <<"c="<<c<<" "
             <<"d="<<d<<" "
             <<"e="<<e<<" "
             <<"g="<<g<<" "<<'\n';
    
    decltype(fun()) sum;
    const int ci=0,&cj=ci;
    decltype(ci) x=0;       //x的类型是const int
    decltype(cj) y=x;       //y的类型是const int&,y绑定到变量x
    //decltype(cj) z; 错误:z是一个引用，必须初始化
    int i=42,*p=&i,&r=i;
    decltype(r+0) b;        //正确:加法的结果是int,因此b是一个(未初始化的)int
    //decltype(*p) c;错误:c是int&,必须初始化
    //decltype的表达式如果是加上了括号的变量，结果将是引用
    //decltype((i)) d;错误:d是int&,必须初始化
    decltype(i) e;          //正确:e是一个(未初始化的)int

}