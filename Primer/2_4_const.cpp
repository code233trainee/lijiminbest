#include <iostream>
#include <string>
int get_size()
{
    return 12;
};

int fcn()
{
    return 11;
};

int errorHandler()
{
    return 0;
};

extern const int BufSize=fcn();

int main()
{
    //getLocalTime();
    const int bufSize=512;//const对象必须初始化
    //bufSize=400;  const对象创建后就不能再改变
    const int i=get_size();//运行时初始化
    const int j=42;//编译时初始化

    int b=10;
    const int a=b;
    std::cout<<a<<'\n';
    b++;//不影响a的值
    std::cout<<a<<'\n';
    const int &r1=a;
    std::cout<<r1<<"\n";
    //int &r2=a; 错误，试图让一个非常量引用指向一个常量对象
 
    extern const int BufSize;

    int c=42;
    const int &a1=c;
    const int &a2=42;//const int 可以直接用int初始化
    const int &a3=a1*2;
    //int &a4=a1*2; a4是一个普通的非常量引用

    double dval=3.14;
    const int &ai=dval;
    //对于上面两句，编译器为了确保ai能绑定一个整数，将上述代码变成了如下：
    //const int temp=dval; 由双精度浮点数生成一个临时的整型常量
    //const int &ai=temp; 让ai绑定这个临时量
    //因此，如果ai是非常量，上述操作是将ai绑定在一个临时量上面，ai与dval的绑定就没有意义了
    std::cout<<dval<<" "<<ai<<"\n";

    const double pi=3.14;
    // double *ptr=&pi; 类型不匹配(试图让一个非常量指针指向一个常量指针)    
    const double *cptr=&pi;
    std::cout<<cptr<<" "<<*cptr<<'\n';
    //*cptr=42;  表达不可修改 
    cptr=&dval;//允许指向常量的指针，指向一个非常量对象

    int errNumb=1;
    int *const curErr=&errNumb;
    const double ip=3.14;
    const double *const pip=&ip;
    if(*curErr)
    {
        errorHandler();
        *curErr=0;
        std::cout<<errNumb<<"\n";
    }
    int i2=20;
    const int v=-1,&r=0;
    int *const p2=&i2;
    const int *const p3=&i2;//
    const int *pl=&i2;
    
    const int *p=nullptr;//p是一个指向整型常量的指针(这是底层const)
    constexpr int *q=nullptr;//q是一个指向整数的常量指针（相当于顶层const）
    //在限定符constexpr声明中如果定义了一个指针，限定符constexpr仅对指针有效，与指针所指对象无关
    int null=0,*p4=&null;
    
    //若const修饰函数则表示函数的返回值不能改变
    //若const修饰函数内部的参数则表示在函数内部不能改变这个参数
    //一个类的成员函数可以被声明为const，这意味着这个成员函数不会修改类的任何成员变量（除非这些变量被声明为mutable）
}