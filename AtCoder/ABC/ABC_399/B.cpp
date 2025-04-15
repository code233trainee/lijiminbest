#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int n;
    // cin >> n;
    // map<int, int> ma;
    // vector<int> a(n), b(n);
    // for(int i = 0; i < n; i++)
    // {
    //     cin >> b[i];
    //     a[i] = b[i];
    // }
    // sort(b.begin(), b.end());
    // int cnt = 1;
    // int r_cnt = 1;
    // for(int i = n-1; i >= 1; i--)
    // {

    // }
    // // b.resize(unique(b.begin(), b.end()) - b.begin());
    // int k = b.size();
    // int num = 1;
    // for(int i = k-1; i >= 0; i--)
    // {
    //     ma[b[i]] = num;
    //     num++;
    // }
    // for(int i = 0; i < n; i++)
    // {
    //     cout << ma[a[i]] << "\n";
    // }
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> rank(n);
    int r = 1;
    while (true) {
        int x = 0;
        //找最大值
        for (int i = 0; i < n; i++) {
            //如果每个值都被访问过了，那么x就是0
            if (rank[i]) continue;
            x = max(x, p[i]);
        }
        if (!x) break;
        //找当前的值的个数
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == x) {
                rank[i] = r;
                k++;
            }
        }
        r += k;
    }
    for (int i = 0; i < n; i++) {
        cout << rank[i] << '\n';
    }
    return 0;
}