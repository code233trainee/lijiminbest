#include <bits/stdc++.h>
using namespace std;
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    //问题简化为查找以n结尾的k个连续整数之和是否为偶数
    //等差数列Sn=(n*(a1 + an))/2
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        cout << (((n*(1 + n)/2) - ((k-n)*(1+(n - k)))/2) % 2 ? "NO" : "YES") << endl;
    }
}