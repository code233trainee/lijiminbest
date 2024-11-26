#include <string>
#include <iostream>
 using Mytype=std::pair<bool,std::pair<float,float>>;
 Mytype solveQuadratic(float a,float b,float c)

{   
    float f=std::pow(b,2);
    float g=4*a*c;
    float e=f-g;
    if(e<0)
        return std::make_pair(false,std::make_pair(0,0));
    float h=std::pow(f-4*a*c,1.f/2.f);
    float x=(-b+h)/(2.f*a);
    float x2=(-b-h)/(2.f*a);
    std::pair<float,float> result={x,x2};
    return std::make_pair(true,result);
}

int main()
{
    while(1)
    {
    float a=2;
    float b=4;
    float c=1;
    std::cin>>a>>b>>c;
    //std::pair<bool,std::pair<float,float>> d=solveQuadratic(a,b,c);
    auto d=solveQuadratic(a,b,c);
    if(d.first)
    {
        std::cout<<"函数有根,"<<"第一个根:"<<d.second.first<<" 第二个根:"<<d.second.second<<std::endl;
    }
    else
    {
        std::cout<<"函数没有根"<<std::endl;
    }
    }
}