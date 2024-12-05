#include <bits/stdc++.h>
using namespace std;
//jiangly
//
// int query(int l, int r)
// {
//     cout << "? " << l << " " << r << endl;
//     long long ans;
//     cin >> ans;
//     return ans;
// }
// void solve()
// {
//     //找子序列"01"
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     for(int i = 1; i < n; i++)
//     {
//         a[i] = query(1, i + 1);
//     }
//     if(a == vector(n, 0LL))
//     {
//         cout << "! IMPOSSIBLE" << endl;
//         return;
//     }
//     int i = 0;
//     while(a[i] == 0)
//     {
//         i++;
//     }
//     string s(n, '0');
//     for(int j = 0; j < i - a[i]; j++)
//     {
//         s[j] = '1';
//     }
//     for(int j = i; j < n; j++)
//     {
//         s[j] = (a[j] > a[j - 1] ? '1' : '0');
//     }
//     cout << "! " << s << endl;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         solve();
//     }
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  //系统回复是包含'01'的子序列的数量
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    auto Ask = [&](int l, int r) {
      if (r - l <= 1) {
        return 0;
      }
      cout << "? " << l + 1 << " " << r << endl;
      int got;
      cin >> got;
      return got;
    };
    int x = Ask(0, n);
    if (x == 0) {
      cout << "! IMPOSSIBLE" << endl;
      continue;
    }
    string s = "";
    for (int i = 0; i < n; i++) {
      int y = Ask(i + 1, n);
      if (y == x) {
        s += "1";
      } else {
        s += "0";
        if (y == 0) {
          s += string(x, '1');
          s.resize(n, '0');
          break;
        }
        x = y;
      }
    }
    cout << "! " << s << endl;
  }
  return 0;
}