
#include <bits/stdc++.h>
using namespace std;

bool check(int g, const vector<int>& a, int n, int k) {
    int count = 0;
    for (int x : a) {
        if (x % g == 0) count++;
    }
    return count >= n - k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxA = *max_element(a.begin(), a.end());

    int left = 1, right = maxA, result = 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid, a, n, k)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}
