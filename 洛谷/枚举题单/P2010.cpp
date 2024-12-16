#include <bits/stdc++.h>
using namespace std;
int i,j,n,m,a,b,c,sum,ans;
int s[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
//我们在这里并不关心是否是闰年，因为9220229是闰年，也就是说我们一点会遍历到这个情况
int main()
{
    cin >> n >> m;
    for(int i = 1; i < 13; i++)
    {
        for(int j = 1; j <= s[i]; j++)
        {
            c=(j%10)*1000+(j/10)*100+(i%10)*10+(i/10);
            sum=c*10000+i*100+j;
            if(sum<n || sum>m)
            {
                continue;
            }
            ans++;
        }
    }
    cout << ans;
    return 0;
}