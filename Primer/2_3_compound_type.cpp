#include <iostream>
#include <string>
#include "test.h"
void compound(int c) //int ac=c;
{
    c+=10;
};

void type(int &ab)//int &ab=cd;
{
    ab+=10;
};
int main()
{
    int ival=1024;
    int &refVal=ival;
    //int &reVal2; 引用必须被初始化
    int &refVal3=refVal;
    int i=refVal;
    double dval=3.14;
    //int &refVal5=dval 引用必须类型匹配

    int a=0,&ra=a;
    a=5;
    ra=10;
    std::cout<<a<<" "<<ra<<'\n';//输出两个10


    double b=0,&rb=b;
    rb=3.14159;
    rb=ra;
    a=rb;
    ra=b;

    int c=10;
    compound(c);
    std::cout<<" c= "<<c<<std::endl;
    int cd=10;
    type(cd);
    std::cout<<" cd= "<<cd<<std::endl;

    double dval2=9.9;
    double *pd=&dval2;//初始值是double对象的地址（&取址操作符）
    double *pd2=pd;//初始值是指向double对象的指针
    //int *pi=pd; 指针pi的类型与pd的类型不匹配
    //pi=&dval; 试图把double型对象的地址赋给int型指针
    std::cout<<pd<<" "<<*pd2<<'\n';//解引用符(*)，由符号*得到*pd和*pd2所指的对象，输出9.9
    dval2=199.9;
    *pd=299.9;//两个指针均指向了dval2
    *pd2=0;//相当于重复赋值，最后一次赋值为最终值
    std::cout<<dval2<<"\n";

    int *p1=nullptr;//()
    double *p2=0;
    int *p3=NULL;//三个空指针;

    int zero=0;
    //p1=&zero; 不能把int变量直接赋给指针;
    if(pd2==p2)
    {
        std::cout<<"trun"<<"\n";
    }
    else
    {
        std::cout<<"fause"<<"\n";
    }

    int m=42;
    int *pl=&m;
    *pl=(*pl) * (*pl);
    std::cout<<m<<"\n";

    void*p=&m;//void*能存放任意类型对象的地址

    int ival2=1024;
    int *pi=&ival2;
    int **ppi=&pi;

    int *p4;
    int *&r=p4;//从右往左读
    r=&m;
    *r=0;

    std::cout<<"a: "<<MyTest::a<<"MyI: "<<MyTest::MyI<<"\n";
}