#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isPrime(long long n) {
    if (n < 2) return false; // 1 和 0 不是质数
    // 从 2 到 sqrt(n) 遍历
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // 找到因子则不是质数
    }
    return true; // 没有找到因子，则是质数
}