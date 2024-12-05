#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> coeff(n, n + 1);
    //花括号限定作用域
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cnt += (s[i] == 'L');
            coeff[i] = min(coeff[i], cnt);
        }
    }
    //每次遇到不会的题，看完大佬的代码之后我都会感叹解法之精妙
    //才能有继续把这个事业进行下去的动力
    {
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            cnt += (s[i] == 'R');
            coeff[i] = min(coeff[i], cnt);
        }
    }
    //选择之后不能再次选择的是索引(分数还是可以再继续加的，如果能再次经过的话)
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        //这个解法是贪心，即每次选择索引都尽可能的包含多的数字
        //coeff数组包含的就是每个数字最多能够被选择的次数
        ans += (long long)(coeff[i]) * a[i];
    }
    cout << ans << "\n";
    /*
    * 例如: {1, 2, 3, 4, 5},"LRLRR"
    * 对应的coeff数组就是{1,1,2,2,1}
    * 对应的答案就是22
    */
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}