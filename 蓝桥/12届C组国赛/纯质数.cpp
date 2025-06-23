#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 2£¬3£¬ 5£¬ 7£¬ 
bool isPrime(int a)
{
	for(int i = 2; i * i <= a; i++)
	{
		if(a % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool check(int a)
{
	while(a)
	{
		int k = a % 10;
		a /= 10;
		if(k == 2 || k == 3 || k == 5 || k == 7)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int cnt = 0;
	for(int i = 2; i <= 20210605; i++)
	{
		if(check(i))
		{
			if(isPrime(i))
			{
				cnt++;	
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
