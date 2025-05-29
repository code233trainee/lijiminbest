#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    int t = gcd(x, y);
    x /= t;
    y /= t;
    for(auto xx : sieve(y))
    {
        if(xx > k)
        {
            cout << -1 << endl;
            return;
        }
    }
    for(auto xx : sieve(x))
    {
        if(xx > k)
        {
            cout << -1 << endl;
            return;
        }
    }
    int res = 0;
    const int inf = 1e9;
    auto check = [&](int a) -> void {
        if(a == 1) return;
        auto d = sieve(a);
        sort(d.begin(), d.end());
        set<int> f;
        f.insert(1);
        for(int i = 1; ; i++)
        {
            set<int> g;
            for(auto t : f)
            {
                for(int yy : d)
                {
                    if(yy > k)
                    {
                        break;
                    }
                    g.insert(t * yy);
                }
            }
            if(g.count(a))
            {
                res += i;
                return;
            }
            f = g;
        }
    };
    check(x);
    check(y);
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}