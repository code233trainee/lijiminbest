#include <string>
#include <iostream>
//struct和class默认成员访问权限为公有和私有（唯一区别）
struct Student//结构体类型
{
    std::string name;
    std::string state;
    int age=0;
};
//全局空间可以定义变量但是不能对变量进行操作
//int i=0;
//i=10;
void printStudentInfo(Student s)
{
    std::cout<<s.name<<" from "<<s.state;
    std::cout<<" ("<<s.age<<")"<<std::endl;
}
Student randomStudentFrom(std::string name)
{
    Student s;
    s.name ="HHHHH";
    s.state =s.name;//为什么state还是“abc”
    s.age =std::rand();
    return s;
}
std::string func(std::string g)
{
    
    return "0";
}
 std::pair<bool,Student> lookupStudent(std::string name)
 {
    Student blank;
   // if (notFound(name)) 
     //   return std::make_pair(false,blank);
    //Student result = getStudentWhitname(name);
    return std::make_pair(true,blank);
 }
int main()
{   
    std::string str="hello world";
    //auto 表示系统自己推导变量的类型
    auto var=std::make_pair(str,str);
    //var=10;//类型不同不能赋值

    auto a=3;
    auto b=4.3;
    auto c='x';
    //const char*
    auto d="hello";

    Student s;//student类型的一个变量"s"
    s.name="Haven";
    s.state="AR";
    s.age=21;
    Student s2;
    s2.name="abc";
    s2.state="ku";
    s2.age=18;
    Student s3{"abc","ku",19};
    //std::cout<<s2.name<<std::endl<<s2.state<<std::endl<<s2.age<<std::endl;
    //std::cout<<s.name<<std::endl<<s.state<<std::endl<<s.age<<std::endl;
    printStudentInfo(s);
    printStudentInfo(s2);
    printStudentInfo(s3);
    //打印一个函数的返回值
    Student t=randomStudentFrom("abc");
    printStudentInfo(t);
    
    //直接嵌套调用
    //一个函数的返回值作为另一个函数的参数
    printStudentInfo(randomStudentFrom("abcde"));

    //函数可以嵌套调用，只要返回值与输入参数类型一致
    func(func(func("abcd")));

    std::pair<int,std::string> ab{2,"abcd"};
    std::cout<<"first:"<<ab.first<<" second:"<<ab.second<<std::endl;


    std::pair<bool,Student> output =lookupStudent("Julie");



  
}