#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    vector <long long> cost;
    long long c = 3;
    long long cnt = 1;
    for (int i = 0; i < 21; ++i) {
        cost.push_back(c);
        c = 3 * c + cnt;
        cnt *= 3;
    }

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long min_k = 0;
        long long min_cost = 0;
        int sz = 0;
        while (n) {
            min_k += n % 3;
            min_cost += (n % 3) * cost[sz];
            n /= 3;
            sz++;
        }
        cout << min_cost << '\n';
    }
    
    return 0;
}