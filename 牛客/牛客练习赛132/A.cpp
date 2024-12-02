#include <bits/stdc++.h>
using namespace std;
int N, a[2000009];
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++) 
    {
        scanf("%d",&a[i]);
    }
    if(N==1) 
    {
        printf("0.00");
        return 0;
    }
    std::sort(a+1,a+N+1);
    long double as=a[1]+a[2];
    for(int i=3;i<=N;i++) 
    {
        as+=2*a[i];
    }
    printf("%.2Lf",as/2);
}