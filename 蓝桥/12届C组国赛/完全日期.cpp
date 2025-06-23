#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//能被4整除但是不能被100整除，或者能被400整除，的为闰年 (2月有29天) 
int daymore[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dayless[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isrun(int a)
{
	if((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool check(int year, int mon, int day)
{
	int total = 0;
	while(year)
	{
		int k = year % 10;
		year /= 10;
		total += k;
	}
	while(mon)
	{
		int k = mon % 10;
		mon /= 10;
		total += k;
	}
	while(day)
	{
		int k = day % 10;
		day /= 10;
		total += k;
	}
	int t = sqrt(total);
	if(t*t == total)
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
	int cnt = 0;
	for(int i = 2001; i <= 2021; i++)
	{
		if(isrun(i))
		{
			for(int j = 1; j <= 12; j++)
			{
				for(int k = 1; k <= daymore[j]; k++)
				{
					if(check(i, j, k))
					{
						cnt++;	
					}						
				}
			}
		}
		else
		{
			for(int j = 1; j <= 12; j++)
			{
				for(int k = 1; k <= dayless[j]; k++)
				{
					if(check(i, j, k))
					{
						cnt++;	
					}						
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
