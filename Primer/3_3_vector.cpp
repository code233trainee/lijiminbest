#include <iostream>
#include <vector>
#include <cctype>
int main()
{
    std::vector<char> str{10};
    char grade;
    while (std::cin>>grade)
    {
        str.push_back(grade);    
    }

    for(auto it=str.begin();it!=str.end();it++)//记得判断begin与end的返回是否相同，小心数组越界
    {
        std::cout<<*it<<" ";
    }
    for(auto &k:str)//对于str中的每个元素
    {
        k=toupper(k);
        std::cout<<str[k]<<" ";
    }
    
    
}