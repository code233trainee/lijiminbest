#include <iostream>
#include <vector>
using namespace::std;
int main()
{
    unsigned rows;
    cout<<"输入需要的行数:";
    cin>>rows;
    unsigned emp;
    for(unsigned k=1;k<=rows;k++)//k为正处于的行数
    {
        unsigned a=k+(rows-1);//每一行的个数
        unsigned b=(rows-k);//符号前的空格数
        unsigned c=b;
        while(b!=0)
        {
            cout<<" ";
            b--;
        }
        while((a-c)!=0)
        {
            if(((a-c)%2)==1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        a--;
        }
        cout<<endl;
    }                                       
}