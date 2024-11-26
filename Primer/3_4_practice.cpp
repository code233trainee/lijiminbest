#include <iostream>
#include <vector>
#include <string>
using namespace::std;
int main()
{
    vector<string> text{"hello word ni hao shi jie"};
    vector<char> c;
    for(auto it=text.begin();it!=text.end();it++)
    {
        for(unsigned k=0;k<it->size();k++)
        {    
            if(!it -> empty())//it->empty()等价于(*it).empty()
            {
                c.push_back((*it)[k]);
            }
        }
    }
    for(auto &ch:c)
    {
        ch=toupper(ch);
        cout<<ch<<" ";
    }
    
}