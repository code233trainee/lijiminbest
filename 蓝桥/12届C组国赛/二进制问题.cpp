#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
bool check(int a)
{
	int t = 0;
	while(a)
	{
		if(a&1)
		{
			t++;
		}
		a = a >> 1;
	}
	if(t == k)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	cin >> n >> k;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(check(i))
		{
			cnt++;	
		}	
	}
	cout << cnt << endl;
	return 0;
}
