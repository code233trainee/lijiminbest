#include <iostream>
#include "currency.h"
#include <stdexcept>//包含标准异常的头文件

template <class T>
bool make2dArray(T ** &x,int numberOfRows,int numberOfColumns)
{
    try
    {
        //创建行指针
        x=new T* [numberOfRows];

        //为每一行分配空间
        for(int i=0;i<numberOfRows;i++)
        {
            x[i]=new int [numberOfColumns];
        }
        return true;
    }
    catch(fasdf) 
    {
        return false;
    }
}

double divide(double a,double b)
{
    if(b==0)
    {
        throw std::runtime_error("除数不能为0");//抛出一个运行时异常
    }
    return a/b;
}

void aaa()
{
    currency* m=new currency(currency::signType::plus,8,12);
    std::cout<<"-----------------"<<std::endl;
    delete m;


    // for(int i=0;i<5;i++)
    // {   
    //     currency a(currency::signType::plus,i,i);
    //     std::cout<<"-----------------"<<a.getDollars()<<std::endl;
    // }
    // int n=3;
    // while (n>0)
    // {
    //     currency a;
    //     std::cout<<"这是while-----------------"<<std::endl;
    //     n--;
    // }
}



int main()
{
    //throw出来的对象需要catch获取
    // try
    // {
    //     std::cout << divide(10,0) << std::endl;
    // }
    // catch(const std::runtime_error& e)
    // {
    //     std::cerr << "发生错误:" << e.what() << '\n';//捕获异常
    // }


    // int n=100;
    // float* x=new float[n];

    currency g,h(currency::signType::plus, 10),i,j;
    //两种形式的setValue
    g.setValue(currency::signType::plus, 3, 50);
    i.setValue(-6.45);

    //调用成员函数add和output
    j = h.add(g);
    h.output();
    std::cout << "+";
    g.output();
    std::cout << "=";
    j.output();
    std::cout << std::endl;

    //连续两次调用成员函数add
    j = i.add(g).add(h);
    i.output();
    std::cout << "+";
    g.output();
    std::cout << "+";
    h.output();
    std::cout << "=";
    j.output();
    std::cout<<std::endl;

    //调用成员函数increment和add
    //increment函数传入的是一个引用,返回值是修改过后的调用这个函数的对象
    i.output();
    std::cout << "+";
    j = i.increment(g).add(h);
    g.output();
    std::cout << "+";
    h.output();
    std::cout << "=";
    j.output();
    std::cout<<std::endl;

    //测试异常
    std::cout<< "Attempting to initiallize with cents = 152" <<std::endl;
    try
    {
        i.setValue(currency::signType::plus,3,152);
    }
    catch(illegalParameterValue e)
    {
        std::cout << "Caught throw exception" << std::endl;
        e.outputMessage();
    }
    
}