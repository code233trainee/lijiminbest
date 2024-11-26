#include <iostream>
using namespace std;
//选择排序的伪码描述
//void SelectionSort(int list,int N)
//{ 将N个整数list[0]到list[N-1]进行非递减排序
//      for(int i=0;i<N;i++)
//      {
//          MinPosition=ScanForMin(List,i,N-1);
//          从list[i]到list[N-1]中找最小元素，并将其位置赋给MinPostition
//          Swap(List[i],List[MinPosition]);//swap函数应该怎么实现？
//          将未排序部分的最小元换到有序部分的最后位置
//      }
//}
int ScanForMin(int List[],int i,int N)
{
    int j;
    for(j=i+1;j<N;j++)
    {
        if(List[j]<List[i])
        {
            i=j;
        }
    }
    return i;
}
void SelectionSort(int List[],int N)
{
    for(int i=0;i<N;i++)
    {
        int MinPosition=ScanForMin(List,i,N-1);
        swap(List[i],List[MinPosition]);
    }
    for(int j=0;j<N-1;j++)
    {
        cout<<List[j]<<endl;
    }
}
int main()
{
    int List[]={3,5,4,4,9,2,1};
    int N=7;
    SelectionSort(List,N);
}



