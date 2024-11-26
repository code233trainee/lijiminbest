#include <string>
#include <iostream>

// /*
// *注释对/* */不能嵌套。
// *”不能嵌套“几个字会被认为是源码，
// *像剩余程序一样处理
// */

// /*
// *单行注释中的任何内容都会被忽略
// *包括嵌套的注释对也一样会被忽略
// */
int main()
{
    //std::cout<<"/*";
    //std::cout<<"*/";
    //std::cout<</*"*/"*/";
    //std::cout<</*"*/"/*"/*"*/;

    int sum=0,val=1;
    //只要val小于1，程序持续执行
    while( val<=10 )
    {
        sum += val;
        //sum=sum+val
        ++val;
        //假设val=5，那么a=val++（a=5，val=6），a=++val（a=6，val=6）
    }
    std::cout<<"1到10的和:"<<sum<<std::endl;

    int a=50,b=51;
    while(b<=100)
    {
        a += b;
        b++;
    }
    std::cout<<"50到100的和:"<<a<<std::endl;

    //用for循环打印出10到1
    for(int p=10;p>0;p--)
    {
        std::cout<<p<<" ";
    }
    std::cout<<";";

    //读取数量不定的输入数据
    //int m=0,value=0;
    //while循环判断输入是不是为int类型的数据，如果是则用户继续输入，不是则把输入的非int类型的数据相加结束循环
    //或者输入文件结束符ctrl+z然后按enter or return
    //while(std::cin>>value)
    //{
    //    m+=value;
    //}
    //std::cout<<"m is: "<<m<<std::endl;


    //寻找相同的数据出现了多少次
    //currrVal是我们正在统计的数;我们将新读入的值存在c
    int currVal=0,c=0;
    if(std::cin>>currVal)
    {
        int cnt=1;
        while(std::cin>>c)
        {
            if(c == currVal)
            {
                cnt++;
            }
            else
                {
                    std::cout << currVal <<" occurs "
                              << cnt     <<" times "<<std::endl;
                    currVal = c;
                        cnt = 1;           
                        
                }
                
        }
        std::cout<< currVal <<" occurs "
                 << cnt     <<" times "<<std::endl;
    }

    printf("hello world");
}

