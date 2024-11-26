#include <iostream>
#include <vector>
using namespace std;
using namespace linkList;
// typedef struct PolyNode* Polynomial;
// struct PolyNode 
// {
//     int coef;
//     int expon;
//     Polynomial link;
// };

//线性表：由同类型数据元素构成有序序列的线性结构
//表中元素个数称为线性表的长度
//线性表没有元素时，称为空表
//表起始位置成为表头，表结束位置称为表尾

//类型名称：线性表(List)
//数据对象集：线性表是n(>=0)个元素构成的有序序列(a1,a2,...,an)
//操作集：线性表基本操作主要有：
//1.List MakeEmpty(): 初始化一个空线性表L;
//2.ElementType FindKth(int K,List L): 根据位序K，返回相应的元素;
//3.int Find(ElementType,List L): 在线性表L中查找X的第一次出现的位置;
//4.void Insert(ElementType X,int i,List L): 在位序i前插入一个新元素X;
//5.void Delete(int i,List L): 删除指定位序i的元素;
//6.int Lenth(List L): 返回线性表L的长度n;

// typedef struct LNode* List;

namespace arrayList
{
#define MAXSIZE 10

template <typename ElementType>
struct LNode{
    using List = LNode<ElementType>*;

    ElementType Data[MAXSIZE];
    int Last;
};
// sizeof(T);
// sizeof(LNode<T>);
// LNode<T>* MyPtr = (LNode<T>*)malloc();

template <typename T>
using List = LNode<T>*;

// 模板特化
typedef LNode<int>* IntergerList; 

// struct LNode L;
// List Ptrl;
template <typename T>
LNode<T>* MakeEmpty()
{
    List<T> PtrL;
    PtrL=(List<T>)malloc(sizeof(LNode<T>));
    PtrL->Last=-1;
    return PtrL;
}

template <typename T>
int Find(T X,List<T> PtrL)
{
    int i=0;
    while(i<PtrL->Last && PtrL->Data[i]!=X)
    {
        i++;
    }
    if(i>PtrL->Last)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template <typename T>
void Insert(T X,int i,List<T> PtrL)
{
    int j;
    if(PtrL->Last==MAXSIZE-1)
    {
        cout<<"表满，不能插入"<<endl;//表空间已满，不能插入
        return;
    }
    if(i<1 || i>PtrL->Last+2)//检查插入位置的合法性
    {
        cout<<"位置不合法"<<endl;
        return;
    }
    for(j=PtrL->Last;j>=i-1;j--)
    {
        PtrL->Data[j+1]=PtrL->Data[j];//将元素倒序向后移动
    }
    PtrL->Data[i-1]=X;//新元素插入
    PtrL->Last++;//Last仍指向最后元素
    return;
}
template <typename T>
void Delete(int i,List<T> PtrL)
{
    int j;
    if(i<1 || i>PtrL->Last+1)//检查空表及删除位置的合法性
    {
        cout<<"不存在第"<<i<<"个元素"<<endl;
        return;
    }
    for(j=i;j<=PtrL->Last;j++)
    {
        PtrL->Data[j-1]=PtrL->Data[j];//将a(i+1)~an顺序向前移动
    }
    PtrL->Last--;//Last仍指向最后元素
    return;
}
}

namespace linkList
{
//线性表的链式存储实现;
//不要求逻辑上相邻的两个元素物理上也相邻;
//通过"链"建立起数据元素之间的逻辑关系。
//插入，删除不需要移动数据元素，只需要修改"链"。

template <typename T>
struct LNode{
    T Data;
    LNode<T>* Next;
};
template <typename T>
using List=LNode<T>*;
// struct Lnode L;
// List PtrL;
template <typename T>
int Length(List<T> PtrL)//求表长
{
    List<T> p=PtrL;//p指向表的第一个节点
    int j=0;
    while(p)//p指向null时结束循环
    {
        p=p->Next;
        j++;//当前p指向的是第j个结点
    }
    return j;
}
template <typename T>
List<T> FindKth(int K,List<T> PtrL)//按序号查找
{
    List<T> p=PtrL;
    int i=1;
    while(p!=NULL && i<K)
    {
        p=p->Next;
        i++;
    }
    if(i==K)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}
template <typename T>
List<T> Find(T X,List<T> PtrL)//按值查找
{
    List<T> p=PtrL;
    while(p!=NULL && p->Data !=X)
    {
        p=p->Next;
    }
    return p;
}
//插入元素
//先构造一个新结点，用s指向;
//再找到链表的第i-1个结点，用p指向;
//然后修改指针，插入结点(p之后插入新结点是s)
template <typename T>
LNode<T>* InsertList(T X,int i,LNode<T>* PtrL)
{
    List<T> p,s;
    if(i==1)//新结点插入在表头
    {
        //模板类带模板参数<T>
        s=(List<T>)malloc(sizeof(LNode<T>));//申请，填装结点
        s->Data=X;
        s->Next=PtrL;
        return s;//返回新表头指针
    }
    p=FindKth(i-1,PtrL);//查找第i-1个结点
    if(p==NULL)//第i-1个不存在，不能插入
    {
        cout<<"参数i错"<<endl;
        return NULL;
    }
    else
    {
        s=(List<T>)malloc(sizeof(LNode<T>));//申请，填装结点
        s->Data=X;
        s->Next=p->Next;//新结点插入在第i-1个结点的后面
        p->Next=s;
        return PtrL;
    }

}

template <typename T>
List<T> Delete(int i,List<T> PtrL)
{
    List<T> p,s;
    if(i==1)//若要删除的是表的第一个结点
    {
        s=PtrL;//s指向第一个结点
        if(PtrL!=NULL)//从链表中删除
        {
            PtrL=PtrL->Next;
        }
        else
        {
            return NULL;
        }
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);//查找第i-1个结点
    if(p==NULL)
    {
        cout<<"第"<<i-1<<"个结点不存在"<<endl;
        return NULL;
    }
    else if(p->Next==NULL)
    {
        cout<<"第"<<i<<"个结点不存在"<<endl;
    }
    else
    {
        s=p->Next;//s指向第i个结点
        p->Next=s->Next;//从链表中删除
        free(s);//释放被删除结点
        return PtrL;
    }
}

template <typename T>
void PrintLinkList(LNode<T>* InHead)
{
    linkList::LNode<int>* p=InHead;
    // for(int j=1;j<=Length(p);j++)
    // {
    //     linkList::LNode<int>* s=FindKth(j,p);
    //     if(s)
    //     {
    //         cout<<"LinkList "<<j<<"= "<<s->Data<<endl;
    //     }    
    // }
    int i=1;
    while(p)
    {
        cout<<"linkList "<<i<<"= "<<p->Data<<endl;
        p=p->Next;
        i++;
    }
    cout<<"------------------------------------------------"<<endl;
}
}

//广义表
//广义表是线性表的推广
//对于线性表而言，n个元素都是基本的单元素;
//广义表中，这些元素不仅可以是单元素也可以是另一个广义表
template <typename T>
struct GNode{
    int Tag;               //标志域：0表示结点是单元素，1表示结点是广义表
    union/*(联合)*/{       //子表指针域Sublist与单元素数据域Data复用，即共用存储空间
        T Data;
        GNode<T>* SubList;
    }URegion;
    GNode<T>* Next;//指向后继结点
};

//多重链表：链表中的节点可能同时隶属于多个链
//多重链表中结点的指针域会有多个，如前面例子包含了Next和SubList两个指针域;
//但包含两个指针域的链表并不一定是多重链表，比如在双向链表不是多重链表
//多重链表有广泛的用途:基本上如树，图这样相对复杂的数据结构都可以采用多重链表方式实现存储

//采用一种典型的多重链表----十字链表来存储稀疏矩阵
//只存储矩阵非零元素项结点的数据域：行坐标Row,列坐标Col，数值Value
//每个结点通过两个指针域，把同行，同列串起来;
//行指针(向右指针)Right
//列指针(向下指针)Down
int main()
{
    int source[] ={3,4,5,6,2};  
    // linkList::LNode<int>* Head=new linkList::LNode<int>;
    linkList::LNode<int>* Head= nullptr;

    // Head = (linkList::LNode<int>*)malloc(sizeof(linkList::LNode<int>));
    // Head->Next=NULL;
    // Head->Data=-1;
    for(int i=0;i<5;i++)
    {
        if(i == 0)
        {
            Head= linkList::InsertList<int>(source[i],i+1,nullptr);
        }
        else
            linkList::InsertList(source[i],i+1,Head);
    }
    int a =Length(Head);
    cout<<"nums lenght:"<<a<<endl;
    //插入和删除操作如果处理的元素位于表头，
    //则需要更新表头指针
    // PrintLinkList(Head);
    // PrintLinkList(InsertList(10,3,Head));
    // PrintLinkList(InsertList(100,4,Head));
    // PrintLinkList(InsertList(99,1,Head));
}