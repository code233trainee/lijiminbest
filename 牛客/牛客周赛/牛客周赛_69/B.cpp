#include <bits/stdc++.h>
using namespace std;
inline long long  rd() {
    long long s=0,m=0;char ch=getchar();//读取第一个字符
    while(!isdigit(ch)) {if(ch=='-')m=1;ch=getchar();}//如果是非数字字符(0-9)则进入
    while( isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();//数字字符则进入，s
    return m?-s:s;
}
int main()
{
    vector<long long> v;
    for(int i = 0; i < 3; i++)
    {
        v.push_back(rd());
    }
    cout << v[2] - v[1] - 1 << "\n";
    return 0;
}