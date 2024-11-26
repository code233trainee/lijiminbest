#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
//clock()捕捉程序从开始运行到clock函数被调用所耗费的的时间
//时间的单位是clock tick，即时钟打点
//常数CLK_TCK：机器时钟每秒所走的时钟打点数(我的机器输出这个常数是1000)

clock_t start,stop;
/*clock_t是clock()函数的返回的变量类型*/
double duration;
/*记录被测函数的运行时间，以秒为单位*/


//多项式问题(一般方法)
//形如f(x)=a0+a1*x+a2^2....+an*x^n
double f1(int n,double a[],double x)
{
    double p=0;
    for(int i=0;i<n;i++)
    {
        a[i]=i;
        p+=a[i]*pow(x,i);//每次做(1+(i-1))次乘法
    }
    return p;
}

//other method
//秦九韶(建议方法，且运行速度快)
//形如f(x)=a0+x*(a1+x*(...(a(n-1)+x*(an))...))
double f2(int n,double a[],double x)
{
    double p=a[n];
    for(int i=n;i>0;i--)
    {
        a[i]=i;
        p=a[i-1]+x*p;//每次只做一次乘法
    }
    return p;
}

double mytime(int n,double a[],double x)
{
    start=clock();
    for(int i=0;i<1000000;i++)//循环调用函数以记录时间
    {
        f2(n,a,x);
    }
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK;
    std::cout<<"tick is:"<<(double)(stop-start)<<std::endl;
    std::cout<<"duration is:"<<duration<<std::endl;
    return 1.0;
}
int main()
{
    /*不在测试范围内的准备工作应写在clock()函数被调用之前*/
    double a[11];
    mytime(10,a,1.1);
    /*其他不在测试范围的处理写在后面，例如输出duration的值*/
}