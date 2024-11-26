#include <iostream>
#include <string>
#include "test.h"
int reused=42;//全局作用域

int main()
{
    extern int MyI;//声明i而非定义i
    std::cout << "My I : " << MyI << std::endl;
    std::cout << "test var : " << MyTest::MyI << std::endl;

    
    int unique=0;//块作用域
    std::cout<<reused<<" "<<unique<<std::endl;//使用全局变量reused，输出42 0
    int reused=0;//新建局部变量reused，覆盖了全局变量reused
    std::cout<<reused<<" "<<unique<<std::endl;//使用局部变量，输出0 0
    std::cout<<::reused<<" "<<unique<<std::endl;//显示的访问全局变量reused;输出42 0

    int a=100,sum=0;
    for(int a=0;a!=10;++a)//判断为真先进行一次循环
       sum += a;          //不加花括号代表只包括语句后的第一行代码
    std::cout<<a<<" "<<sum<<std::endl;

    printf("*");
    return 0;
}