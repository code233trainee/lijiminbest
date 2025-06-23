#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> n >> s;
    map<char, char> ma;   
    for(int i = 0; i < 13; i++)
    {
        ma['a' + i] = 'a' + (25 - i);
        ma[25 - i + 'A'] = 'A' + i;
    }
    int ans = 0;
    stack<char> st;
    for(int i = 0; i < n; i++)
    {
        if(!st.empty())
        {
            if(ma[st.top()] == s[i])
            {
                st.pop();
                ans += 2;
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    cout << n - ans << endl;
    return 0;
}