#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2000010
bool isok[N], isprm[N];
vector<int> prms;
int main()
{
    //把isprm的每个值都设为true(全局自动初始化为false)
    memset(isprm, true, sizeof(isprm));
    for(int i = 2; i < N; i++)
    {
        if(isprm[i])
        {
            prms.push_back(i);
            for(int j = i+i; j < N; j += i)
            {
                isprm[j] = false;
            }
        }
    }
    for(auto i : prms)
    {
        for(auto j : prms)
        {
            if(i*j >= N)
            {
                break;
            }
            if(i != j)
            {
                isok[i*j] = true;
            }
        }
    }
    for(auto x : prms)
    {
        if(1ll*x*x*x*x >= N)
        {
            break;
        }
        isok[x*x*x*x] = true;
    }
    ll n;
    cin >> n;
    int ans = 0;
    for(int i = 2; 1ll*i*i <= n; i++)
    {
        if(isok[i])
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}