#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    int INF = 1e9;
    stack<int> st;
    st.push(INF);
    int mx = 0, ans = 0;
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        while(!st.empty() && st.top() < a)
        {
            ans++;
            mx = max(mx, st.top());
            st.pop();
        }
        st.push(a);
    }
    while(!st.empty() && st.top() < mx)
    {
        ans++;
        st.pop();
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}