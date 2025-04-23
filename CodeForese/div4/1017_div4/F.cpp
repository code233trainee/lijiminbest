#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int N, M, K;
    cin >> N >> M >> K;
    int nk = gcd(N, K);
    int mk = K / nk;
    assert(M % mk == 0);
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a = i % nk * mk + (i + j) % mk + 1;
 
            if (mk == 1)
                a = j % mk * nk + (i + j) % nk + 1;
 
            cout << a << (j < M - 1 ? ' ' : '\n');
        }
    }
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