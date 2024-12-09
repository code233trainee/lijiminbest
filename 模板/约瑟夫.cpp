#include <bits/stdc++.h>
//n是人数，m是死亡数字，返回的是原始数组中胜利者的编号(下标加一)
int cir(int n,int m)
{
	int p=0;
	for(int i=2;i<=n;i++)
	{
		p=(p+m)%i;
	}
	return p+1;
}
int main()
{
    return 0;
}