#include <string>
#include <iostream>
//命名空间可重叠

using namespace std;//申明可以直接使用命名空间“std”里面的内容

namespace stD//定义一个命名空间
{
    class string//定义一个类“string”
    {
        public:
    };
    int getNumber()
    {
        std::cout<<"stD"<<endl;//打印出“stD”
        return 11;//返回“11”
         std::cout<<"stD"<<endl;//不会被执行
    };;
};;;;;;
// 定义一个函数
//最前面是返回值类型（int） 
//然后是函数名（getNumber）
//然后紧跟一对括号，有参数在括号里面填参数，没有参数也必须跟空括号
//再往后跟一对花括号，在花括号里写代码逻辑
//花括号后分号可写可不写
int getNumber()
{   
    std::cout<<"std"<<endl;//打印出“std”
    return 12;//返回“12”
};

using namespace stD;//申明可以直接使用命名空间“stD”里面的内容

//std:
int main()
{
    std::string str("hello world");
    stD::string my;
    stD::getNumber ();
    std::cout<<stD::getNumber()<<endl;//
    
    ::getNumber();//调用全局空间下的函数（getNumber）
    int i= ::getNumber();
    (std::cout << i)<<"jkahfkj";//打印出函数的返回值
}//EOL:end of line