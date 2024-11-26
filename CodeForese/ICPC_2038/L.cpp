#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    //每个桥需要更换板子的数量
    cin >> n;
    // 每个桥的板子的长度：18, 21, 25
    int ans = n * 2 / 3;
    int t = n * 2 % 3;
    ans += (t + n + 1) / 2;
    cout << ans << endl;
}