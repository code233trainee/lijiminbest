#include <iostream>
#include <math.h>
using namespace std;
int text(int num)
{
    num++;
    double d=num/2;
    int e=sqrt(d);
    return e;
}
int printChars(int a,char c)
{
    for(int i=a;i>0;i--)
    {
        cout<<c;
    }
    return -1;
}
int main()
{
    int num=100;
    char c='*';
    //cin>>num>>c;
    const int n=text(num);
    for(int j=n;j>0;j--)
    {
        int nums=1+(j-1)*2;
        int k=n-j;
        printChars(k,' ');
        printChars(nums,c);
        cout<<endl;
    }
    for(int i=2;i<=n;i++)
    {
        int nums=1+(i-1)*2;
        int k=n-i;
        printChars(k,' ');
        printChars(nums,c);
        cout<<endl;
    }
    int more=num-(2*(n*n)-1);
    cout<<more;
}
