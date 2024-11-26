#include <bits/stdc++.h>
using namespace std;
int n,k;
string s;
int id[1000010];
int shu[1000010];
int cnt;
int main()
{
    cin>>n>>k;
	cin>>s;
	int number=0,last=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			number++;
		}
		else if(s[i-1]=='1'&&s[i]=='0')
		{
			id[++cnt]=last;
			shu[cnt]=number;
			number=0;
		}
		if(s[i]=='0'&&s[i+1]=='1')
		{
			last=i+1;
		}
	}
	if(number!=0)
	{
		id[++cnt]=last;
		shu[cnt]=number;
		number=0;
	}
	id[k]=id[k-1]+shu[k-1];
	int now=1;
	for(int i=0;i<n;i++)
	{
		if(i>=id[now]&&i<=id[now]+shu[now]-1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		if(i+1==id[now+1])
		{
			now++;
		}
	}
	return 0;
}
    // vector<pair<int, char>> ss;
    // int st1 = 0, st0 = 0;
    // char last = s[0];
    // char occu = s[0];
    // for(int i = 0; i < n; i++)
    // {
    //     occu = s[i];
    //     if(occu != last)
    //     {
    //         last = occu;
    //         if(occu == '0')
    //         { 
    //             ss.push_back({st1, '1'});
    //             st1 = 0;
    //             st0++;
    //         }
    //         if(occu == '1')
    //         {
    //             ss.push_back({st0, '0'});
    //             st0 = 0;
    //             st1++;
    //         }
    //     }
    //     else
    //     {
    //         if(occu == '0')
    //         {
    //             st0++;
    //         }
    //         if(occu == '1')
    //         {
    //             st1++;
    //         }
    //     }
    //     if(i == (n-1))
    //     {
    //         if(st0 != 0)
    //         {
    //             ss.push_back({st0, '0'});
    //         }
    //         if(st1 != 0)
    //         {
    //             ss.push_back({st1, '1'});
    //         }
    //     }
    // }
    // int l = 0, r = 0;
    // int jujd = 0;
    // int ok = false;
    // for(size_t i = 0; i < ss.size(); i++)
    // {
    //     if(ss[i].second == '1')
    //     {
    //         jujd++;
    //         ok = !ok;
    //     }
    //     if(ok)
    //     {
    //         if(jujd == (k-1))
    //         {
    //             l = i;
    //             ok = !ok;
    //         }
    //         if(jujd == k)
    //         {
    //             r = i;
    //             break;
    //         }
    //     }
    // }
    // swap(ss[l+1], ss[r]);
    // for(size_t i = 0; i < ss.size(); i++)
    // {
    //     for(int j = 0; j < ss[i].first; j++)
    //     {
    //         cout << ss[i].second;
    //     }
    // }
