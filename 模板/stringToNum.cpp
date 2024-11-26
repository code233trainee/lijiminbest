#include <bits/stdc++.h>
using namespace std;
//inline 声明为内联函数，减少函数调用的时间开销
inline int rd() {
    int s=0,m=0;char ch=getchar();//读取第一个字符
    while(!isdigit(ch)) {if(ch=='-')m=1;ch=getchar();}//如果是非数字字符(0-9)则进入
    while( isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();//数字字符则进入，s
    return m?-s:s;
}
int main()
{

}