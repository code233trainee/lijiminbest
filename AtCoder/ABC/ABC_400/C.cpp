#include <iostream>
#include <cmath>
using namespace std;
// 每个正整数都可以表示成一个 2 的幂乘以一个奇数。
int main() {
    // 输入正整数 N
    long long N;
    cin >> N;
    
    long long ans = 0;
    // 对于 v 从 1 开始，当 2^v > N 时停止循环
    for (int v = 1; (1LL << v) <= N; v++) {
        // 计算 N / 2^v
        long double limit = (long double)N / (1LL << v);
        // m 为 s^2 <= N/2^v 的 s 的上界
        long long m = floor(sqrt(limit));
        // 统计 1 到 m 内奇数的个数
        long long cnt = (m + 1) / 2;
        ans += cnt;
    }
    
    cout << ans << endl;
    return 0;
}
