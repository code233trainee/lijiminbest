#include <bits/stdc++.h>
using namespace std;
//多练习一次，大脑就会进步一点
void solve()
{
    int n;
    cin >> n;
    long long adv = 0;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        adv += b[i];
    }
    long long mxv = -1e18;
    for(int i = 1; i <= n; i++)
    {
        long long sm = a[i];
        for(int j = 1; j <= n; j++)
        {
            if(j^i)//快速判断是否相等(相异为true)
            {
                sm += max(0, a[j] - b[j]);
            }
        }
        mxv = max(mxv, sm);
    }
    cout << mxv + adv << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}