#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto& x : A) cin >> x;
    for (int x = N; x >= 0; --x) {
        int count = 0;
        for (auto a : A) {
            if (a >= x) ++count;
        }
        if (count >= x) {
            cout << x << endl;
            break;
        }
    }
}
