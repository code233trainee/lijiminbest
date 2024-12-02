#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin >> n >> s;

    s = " " + s;
    stack<int> st;
    vector<int> ans(n+1);
    int cnt = 0, flag = 0;
    for(int i = 1; i <= n*2; i++)
    {
        if(s[i] == '(')
        {
            st.push(++cnt);
        }
        else
        {
            if(!st.empty())
            {
                ans[st.top()] = st.size();
                st.pop();
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag)
    {
        cout << -1;//无法匹配上则输出-1
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << n - ans[i] << ' ';
    }
}
int main()
{
    solve();
}