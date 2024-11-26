#include <iostream>
#include <string>
using namespace::std;
int main()
{
    //替换字符串中的字符
    string str("ni hao shi jie");
    for(char &a : str)
    {
        a='x';
    }
    cout<<str<<endl;
    
    for(decltype(str.size()) i=0;i <= str.size();++i)
    {
        str[i]='A';
    }
    cout<<str<<endl;

    unsigned j=0;
    while (j<str.size())
    {
        str[j]='B';
        j++;
    }
    cout<<str<<endl;

    string s;
    cout<<'b'<<(int)(s[0])<<'a'<<endl;

    //去掉字符串中的标点符，然后输出
    string ass="hello,world,";
    string bss;
    string css;
    for(unsigned k=0;k < ass.size();++k)
    {

        if(!ispunct(ass[k]))
        {
            bss+=ass[k];
        }
            
    }
    cout<<bss<<endl;
    //用删去字符的函数实现
    for(unsigned len=0;len<ass.size();)
    {
        if(!ispunct(ass[len]))
        {
            
            len++;
        }
        else
        {
            ass.erase(len,1);
        }
    }
    cout<<ass<<endl;

}