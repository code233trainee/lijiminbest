#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>
void printN(int N)//运用循环打印数字
{
    for(int i=1;i<=N;i++)
    {
        printf("%d\n",i);
    }
    return;
}

void printM(int M)//运用递归打印数字，当数据很大的时候程序会崩溃
{
    if(M)
    { 
        printM(M-1);//嵌套的函数
        printf("%d\n",M);
    }
    return;
}



int main()
{
   
}