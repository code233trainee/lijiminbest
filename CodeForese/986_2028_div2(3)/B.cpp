#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll solve()
{
    ll n, b, c;
    cin >> n >> b >> c;
    if(!b){
        if( c >= n) return n;
        if(c + 1 == n) return c;
        if(c + 2 == n) return c + 1;
        return -1;
    }
    if(c >= n) return n;
    return n - ((n - 1 - c) / b + 1);
    //对于最后一步，要求出ai<n的数量，就是我们最后不需要转换的个数，
    //对于b不为零，c<n,排列变成，c,c+b,c+2b,....,c+nb
    //每个元素之间相差b，所以我们可以(n - 1 - c) / b来算出具体数量
    //减c是因为有可能不是从0开始的
    //为什么要减一，是因为题中的美丽数组是[0,...,n-1](不一定顺序递增，只需要保证每个元素是<=n-1,且元素互异)
}
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--)
    {
        cout << solve() << endl;
    }
}