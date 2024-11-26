#include <iostream>
using namespace std;
int factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

template<class T>
T sum(T a[], int n)//返回数值数组元素a[0:n-1]的和
{
    T theSum = 0;
    for(int i = 0; i < n; i++)
    {
        theSum += a[i];
    }
    return theSum;
}
template<class T>
T rsum(T a[], int n)//返回数值数组元素a[0:n-1]的和(递归)
{
    if(n > 0)
    {
        return (rsum(a, n-1) + a[n-1]);
    }
    return 0;
}

//使用递归函数生成排列
template<class T>
void permutations(T list[], int k, int m)
{
    //生成list[k:m]的所有排列
    if(k == m)
    {
        //list[k:m]仅有一个排列，输出它
        copy(list,list+m+1,ostream_iterator<T>(cout,""));
        cout << endl;
    }
    else
    {
        //list[k:m]有多余一个的排列，递归地生成这些排列
        for(int i = k ; i <= m ; i++)
        {
            swap(list[k], list[i]);
            permutations(list, k+1, m);
            swap(list[k], list[i]);
        }
    }
}
int main()
{
    int a[] = {1,3,5,7,9};
    cout << factorial(3) <<endl;
    cout << sum(a,3) <<endl;
    cout << rsum(a,3) <<endl;
}
