#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e6 + 5;
typedef long long ll;
 
int even[maxn], odd[maxn], p[maxn];
int temp[maxn];
ll ans;
 
void merge(int l1, int r1, int l2, int r2, int a[]) {
    int i = l1, j = l2;
    int k = l1;
    while (i <= r1 || j <= r2) {
        // 左边用完了
        if (i > r1) {
            temp[k++] = a[j++];
            continue ;
        }
        // 右边用完了
        if (j > r2) {
            temp[k++] = a[i++];
            ans += j - l2;
            continue ;
        }
        if (a[i] <= a[j]) temp[k] = a[i], i++, k++, ans += j - l2;
        else temp[k++] = a[j++];
    }
    for (int i = l1; i <= r2; i++) a[i] = temp[i];
}
 
 
// g
void Sort(int l, int r, int a[]) {
    if (l == r) return ;
    int mid = (l + r) / 2;
    Sort(l, mid, a);
    Sort(mid + 1, r, a);
    merge(l, mid, mid + 1, r, a);
}
 
 
int a[maxn];
void solve() {
 
    int n;
    cin >> n;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) odd[++x] = a[i];
        else even[++y] = a[i];
        
    }
	ans = 0;
    Sort(1, x, odd);
    ll inv1 = ans;
    ans = 0;
    Sort(1, y, even);
    ll inv2 = ans;
    // cout << inv1 << " " << inv2 << endl;
    if (inv1 % 2 != inv2 % 2) {
        if (n & 1) swap(odd[x], odd[x - 1]);
        else swap(even[y], even[y - 1]);
    }
    int u = 0, v = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) cout << odd[++u] << " ";
        else cout << even[++v] << " ";
    }
    cout << endl;
 
}
 
int main() {
    ios::sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}