#include <string>
#include <iostream>
#include <map>
#include <vector>
int main()
{
    int numzore=(12.5);
    int numOne=12.5;
    //int numtwo{12.f};用花括号初始化更安全
    int numstree{12};


    std::map<std::string,int> ages //map对应对应有两个值<key，value>
    {
        {"Alice",25},
        {"Bob",30},
        {"Charlie",35}
    };
    std::cout<<"Alice`s age:"<<ages["Alice"]<<std::endl;//方括号里面加key类型的值输出对应的value
    std::cout<<"Bob`s age:"<<ages.at("Bob")<<std::endl;//调用成员函数at并输出对应value


    std::vector<int> numbers{2,1,4,4,5};
    for(int i=0;i<numbers.size();i++)
    {
        std::cout<<numbers[i]<<" ";
    }
    std::cout<<std::endl;
}    