#include <iostream>
#include <string>
using std::cin;
int main()
{
    int i;
    cin>>i;
    //cout<<i; 错误:没有对应的using声明，必须使用完整的名字
    std::cout<<i;
}