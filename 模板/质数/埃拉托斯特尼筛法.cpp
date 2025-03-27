#include <bits/stdc++.h>
using namespace std;
// 1不是质数
// 2是唯一的偶质数
vector<int> sieve(int max_n) {
    vector<bool> is_prime(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_n; i++) {
        if(is_prime[i]){
            for (int j = i * i; j <= max_n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= max_n; i++) {
        if(is_prime[i])
            primes.push_back(i);
    }
    return primes;
}
int main()
{
    return 0;
}