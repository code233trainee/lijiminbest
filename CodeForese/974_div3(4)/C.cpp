#include <bits/stdc++.h>
using namespace std;
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> vec(n);
        long long sum = 0;
        for(auto &c : vec)
        {
            cin >> c;
            sum += c;
        }
        sort(vec.begin(),vec.end());//以升序排序
        if( n <= 2)
        {
            cout << -1 << endl;
            continue;
        }
        //注意这里的处理，选取中位数(对于偶数是中间靠右的一个元素,均是严格大于一半的人数)，这个位置的元素如果小于平均值那么罗宾汉就会出现
        //其实就是中位元素小于总财富的一半中位元素aj< (s+x)/(2*n),(s为总财富，x为发现的那个意外金块，n为总人数)，化简后可得最后的式子
        cout << max(0ll, vec[n/2]*2*n-sum+1) << endl;
    }
}