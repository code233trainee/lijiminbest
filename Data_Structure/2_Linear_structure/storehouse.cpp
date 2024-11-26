#include <iostream>
#include <vector>
using namespace std;
//中缀表达式：运算符号位于两个运算数之间。如，a+b*c-d/e
//前缀表达式：运算符号位于两个运算数之后。如，-+a*bc/de
//后缀表达式：运算符号位于两个运算数之后。如，abc*+de/-

//后缀表达式求值策略：从左向右"扫描"，逐个处理运算数和运算符号
//碰到运算数就记住，碰到运算符号就把最近记住的两个数拿来做对应的运算(栈)

//堆栈：具有一定操作约束的线性表
//只在一段(栈顶，top)做插入，删除
//插入数据：入栈(Push)
//删除数据：出栈(Pop)
//后入先出：Last In First Out(LIFO)

//类型名称：堆栈(Stack)
//数据对象集：一个有0个或多个元素的有穷线性表。
//操作集：长度为MaxSize的堆栈S属于Stack，堆栈元素item属于ElementType
//1.Stack CreateStack(int MaxSize): 生成空堆栈，其最大长度为MaxSize;
//2.int IsFull(Stack S,int MaxSize): 判断堆栈S是否已满;
//3.void Push(Stack S,ElementType item): 将元素item压入堆栈;
//4.int IsEmpty(Stack S): 判断堆栈S是否为空;
//5.ElementType Pop(Stack S): 删除并返回栈顶元素

//栈的顺序存储实现
#define MaxSize 10
template <typename T>
struct SNode{
    T Data[MaxSize];
    int Top;//Top表示栈中有几个元素
};

template <typename T1>
class DStack{
public:
    T1 Data[MaxSize];
    int Top1 = -1;//堆栈1的栈顶指针

    void Push(T1 item)
    {
        if(Top1==MaxSize-1)
        {
            cout << "堆栈满" << endl;
        }
        else
        {
            Top1 = Top1 + 1;
            Data[Top1]=item;
            return;
        }
    }

    T1 Pop()
    {
        if(Top1==-1)
        {
            cout<<"堆栈空"<<endl;
            return -1;
        }
        else
        {
            T1 TopValue = Data[Top1];
            Top1 = Top1 - 1;
            return TopValue;
        }
    }
    void PrintElement()
    {
        for(int i=0;i<=Top1;i++)
        {
            
            cout<<Data[i]<<endl;
            
        }
    }
    bool IsFull()
    {
        if(Top1==MaxSize)
        {
            return true;    
        }
        else
        {
            return false;
        }
    }
    bool IsEmpty()
    {
        if(Top1==-1)
        {
            return true;   
        }
        return false;
    }

};

int hailstone(int n)
{
    int i=1;
    while(n>1)
    {
        if(n%2)
        {
            n=n*3+1;
        }
        else
        {
            n=n/2;
        }
        i++;
    }
    return i;
}

//Data Structure + Algorithm
//DSA
//i<<=1,左移一位的操作等价于给i乘2

void bubbleSort(int A[],int n)//冒泡排序
{
    for(bool b=false;b=!b;n--)
    {
        for(int i=1;i<n;i++)
        {
            if(A[i-1]>A[i])
            {
                swap(A[i-1],A[i]);
                b=false;
            }
        }
    }
    for(int j=0;j<8;j++)
    {
        cout<<A[j]<<" ";
    }
}


int Sum(int A[],int n)
{
    int sum=0;
    for(int i=0;i<=n;i++)
    {
        sum+=A[i];
    }
    return sum;
}

//分而治之(Decrease-and-conquer)
int Sum1(int A[],int n)//O(n)  线性递归
{
    return  (n<1)? 0 : Sum1(A,n-1)+A[n];
}

int Sum2(int* A,int lo,int hi)//求范围[lo,hi]内元素的和
{
    if(lo==hi)
    {
        return A[hi];
    }
    else
    {
        int mi=(lo+hi)>>1;//(取中位)右移一位，相当于除以2并向下取整
        return Sum2(A,lo,mi)+Sum2(A,mi+1,hi);
    }
}

// Master Theorem (大师定理)

//斐波那契数列
// n为第几项
int fib(int n)//时间为
{
    return (2 > n) ? n : fib(n-1) + fib(n-2);
    // too slow
    // 各递归的实例均被大量的重复调用
}

int fib2(int n)
{
    //时间为O(n),空间为O(1)
    //动态规划
    int f = 0, g = 1;
    while(1 < n--)
    {
        g = g + f;
        f = g - f;
    }
    return g;
}

//Longest common subsequence(最长公共子序列)
int lcs(string s, string t)
{
    int n = 1;
    if(s[s.length() - n] == t[t.length() - n])
    {

    }
    n++;
    return 0;
}


int main()
{
    DStack<int> S;
    S.Push(2);
    S.Push(4);
    S.Push(6);
    S.Push(7);
    S.Push(8);
    S.PrintElement();
    if(!S.IsEmpty())
    {
        S.Pop();
    }
    // S.Top1=-1;
    // S.Top2=MaxSize;
    cout<<"hailstone lenght:"<<hailstone(99)<<endl;

    int arr[10]={1,3,4,5,89,0,4,76};
    int n=8;
    bubbleSort(arr,n);

    vector<int> varr{11,10,20,30,40};
    cout<<"\nSum= "  <<Sum(arr,2)
        <<"\nSum1= " <<Sum1(arr,2)
        <<"\nSum2= " <<Sum2(varr.data(),1,2)
        <<endl;
    int* k = varr.data();
    for(int i = 0; i < varr.size(); i++)
    {
        cout<<*k++<<endl;
    }
    
    cout << "fib:"  << fib(8)  << endl;
    cout << "fib2:" << fib2(8) << endl;
}