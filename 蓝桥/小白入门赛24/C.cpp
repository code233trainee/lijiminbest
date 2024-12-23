#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> s;
    int n = s.length();
    auto check = [&](int k) -> int{
        unordered_map<string, int> st;
        for(int i = 0; i < n; i++)
        {
            if(i == k)
            {
                continue;
            }
            if(s[i] == 'G' && (i == n - 1 || (i+1) == k))
            {
                return -1;
            }
            if(s[i] == 'G')
            {
                st[s.substr(i, 2)]++;
                i++;
            }
            else
            {
                st[to_string(s[i])]++;
            }
        }
        return st.size() == 7 ? st["G1"] : -1;
    };
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'G')
        {
            ans = max(ans, check(i));
        }
    }
    cout << ans << "\n";
    return 0;
}