#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 attacks(unsigned long long a){
    long long l = 0, r = 1000000000LL;
    while(l < r){
        long long m = (l + r) >> 1;
        long long sum = (long long)m * (m + 1) / 2;
        if(sum >= a) r = m;
        else l = m + 1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unsigned long long x;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> x;
        ans += attacks(x);
    }
    cout << ans << "\n";
    return 0;
}
