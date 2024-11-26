//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//回文数
//是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
#include <iostream>
#include <vector>
#include <string>
using namespace::std;
int main()
{
    int x=123;
    int a=0;
    vector<string> str;
    vector<string> str2;
    if(x>0)
    {
        while(x!=0)
        {
            a=x%10;
            x/=10;
            str.push_back(to_string(a));//转成字符串
        }
        for(int i=str.size()-1;i!=-1;i--)
        {
            str2.push_back(str[i]);
        }
        for(auto c:str)
        {
            cout<<c<<" ";//输出倒序的数字
        }
        cout<<endl;
        for(auto d:str2)
        {
            cout<<d<<" ";//输出顺序的数字
        }
        cout<<endl;
    }
    else//其实如果是负数可以直接判定为false
    {
        //return false
        x=-x;
        while(x!=0)
        {
            a=x%10;
            x/=10;
            str.push_back(to_string(a));//转成字符串
        }
        str.push_back("-");
        for(int i=str.size()-1;i<0;i--)
        {
            str2.push_back(str[i]);
        }
    }
    if(str==str2)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}