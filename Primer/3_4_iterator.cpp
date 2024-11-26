#include <iostream>
#include <vector>
using namespace::std;
int main()
{
    string s("some string");
    if(s.begin()!=s.end())
    {
        auto it=s.begin();
        *it=toupper(*it);
    }
    for(auto it = s.begin() ; it!=s.end()&&!isspace(*it) ; ++it)//读到空格停止
    {
        *it=toupper(*it);
        cout<<*it<<" ";
    }
    cout<<endl;

    //用迭代器实现二分搜索
    vector<string> text{"hello","world","ni","hao","shi"};
    string sought="hello";
    auto beg=text.begin(),end=text.end();
    auto mid=text.begin()+(end-beg)/2;//初始状态下的中间点
    while(mid!=end&&*mid!=sought)//当还有元素未检查且还未找到目标数时进行循环
    {
        if(sought<*mid)//我们要找的元素在前半部分吗？
        {
            end=mid;//如果是，调整搜索范围使得忽略掉后半部分
        }
        else//我们要找的元素在后半部分
        {
            beg=mid+1;//在mid之后寻找
        }
        mid=beg+(end-beg)/2;//新的中间点
    }
    cout<<*mid;
}