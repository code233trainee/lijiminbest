#include <iostream>
//求最大子列问题
int MaxSubseqSum4(int A[],int N)//T(N)=O(N)
{
    int ThisSum=0,MaxSum=0;
    int i;
    for(i=0;i<N;i++)
    {
        ThisSum+=A[i];/*向右累加*/
        if(ThisSum>MaxSum)
        {
            MaxSum=ThisSum;/*如果发现更大的和则更新当前结果*/
        }
        else if(ThisSum<0)/*如果当前子列和为负数*/
        {
            ThisSum=0;/*则不可能使后面的和增大，抛弃之*/
        }
    }
    return MaxSum;
}

//int MaxSubseqSum3()分治法

int MaxSubesqSum2(int A[],int N)//T(N)=O(N^2)
{
    int ThisSum=0,MaxSum=0;
    int i,j;
    for(i=0;i<N;i++)
    {
        ThisSum=0;
        for(j=i+1;j<N;j++)
        {
            ThisSum+=A[j];
            if(ThisSum>MaxSum)
            {
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}

int MaxSubesqSum1(int A[],int N)//T(N)=O(N^3)
{
    int ThisSum=0,MaxSum=0;
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            ThisSum=0;
            for(k=i;k<=j;k++)
            {
                ThisSum+=A[k];
                if(ThisSum>MaxSum)
                {
                    MaxSum=ThisSum;
                }
            }
        }
    }
    return MaxSum;

}

int main()
{
    int A[]={-1,3,-2,4,-6,1,6,-1};
    int N=8;
    std::cout<<MaxSubseqSum4(A,N)<<std::endl
             <<MaxSubesqSum2(A,N)<<std::endl
             <<MaxSubesqSum1(A,N)<<std::endl;
}



