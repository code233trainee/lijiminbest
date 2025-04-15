#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
//欧拉函数是求小于n且与n互质的数
ull Euler(ull n)//求n的欧拉函数(固定模板) 
{
    ull phi=n;
    for(int i=2;i*i<=n;i++)//枚举n的质因数 
    {
        if(n%i)continue;
        while(n%i==0)//i是质因数 
        {
            n=n/i;//n不断除以i直至i不再是n的质因数 
        }
        phi=phi/i*(i-1);//递推欧拉函数,Euler(n)=n/pi*(pi-1) 
    }    
    //最后可能还剩下一个大于n的因子,如12=2*2*3,最后将剩下3,补充上 
    if(n>1)phi=phi/n*(n-1);
    return phi;
}
int main()
{
    return 0;
}