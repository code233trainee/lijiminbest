#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 1e7+5
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
    int t;
    cin >> t;
    vector<int> primes = sieve(N);
    while(t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        
        for(auto z : primes)
        {
            if(z > n)
            {
                break;
            }
            ans += n / z;
        }

        cout << ans << "\n";
    }
    return 0;
}