#include <string>
#include <iostream>
//蓝色对应内置类型（系统内置）
//黄色对应函数
//粉色对应内置关键字
void g(double c)    
{
    std::cout<<c<<std::endl;
    return ;
}
int div_3(int x)
{
    return x/3;
}
std::string speak(int x)
{
    if(x==1)
    {
        return "aaaaa";
    }
    else if(x==2)
    {
        return "bbbbb";
    }
    else if(x==3)
    {
        return "ccccc";
    }
    return "没有对应字符串";
} 
int main()
{   //变量类型
    int val =5;
    char ch ='F';
    float decimalVal1 =5.0;
    double decimaVal2 =5.0;
    bool bVal =true;
    std::string str="Haven";
    //str.append();//调用成员函数
    std::cout<<"int类型:"       <<val          <<std::endl
             <<"char类型:"      <<ch           <<std::endl
             <<"float类型:"     <<decimalVal1  <<std::endl
             <<"double类型:"    <<decimaVal2   <<std::endl
             <<"bool类型:"      <<bVal         <<std::endl
             <<"str类型:"       <<str          <<std::endl;
    //定义变量         
    float a=3.2*5-1;
    auto a2=3.2*5-1;
    auto a3=5/(float)(5/2);
    std::cout<<a3<<std::endl;
    //变量类型无法更改
    int b=100;
    std::string c="afdsk";
    div_3(4);
    //输出对应字符串
    int index=0;
    std::cin>>index;//读入一个数赋给“index”
    std::string t=speak(index);
    std::cout<<"第"<<index<<"句话: "<<t<<std::endl;
   

}

    