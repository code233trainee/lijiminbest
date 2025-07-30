#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    int X = 0;
    for(int i = 0; i + 1 < n; i++){
        if (S[i] == 'Q' && S[i+1] == 'Q')
            X++;
    }

    ll ans;
    if (X > 0) ans = n - X;
    else       ans = n - 1;

    cout << ans << "\n";
    return 0;
}
