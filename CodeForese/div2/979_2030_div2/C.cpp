#include <bits/stdc++.h>
using namespace std;
void solve()
{
    //要使整个表达式为真(爱丽丝赢),只需要保证一个1与其他的或起来
    //and的运算优先级大于或
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '1')
        {
            v[i] = 1;
        }
    }
    bool win = false;
    //首尾有1爱丽丝只需要先手放一个或就是必赢
    if(v[0] || v[n-1])
    {
        win = true;
    }
    //由于爱丽丝先手，即便首尾没有1，但是只需要有连续的两个1，
    //就可以使得1被or围起来，参与最后的计算
    //只需要先在两个1的中间放置一个or，然后是bob，最后再在另一边放置一个or，就可以达到至少一个1被or围起来的效果
    for(int i = 1; i < n; i++)
    {
        if(v[i] && v[i - 1])
        {
            win = true;
        }
    }
    if(win)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
}