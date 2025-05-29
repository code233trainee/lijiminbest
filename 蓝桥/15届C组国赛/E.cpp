#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    set<set<string>> ss;
    while(n--)
    {
        string s;
        cin >> s;
        int len = s.length();
        set<string> st;
        for(int i = 0; i < len; i++)
        {
            if(s[i]=='"')
            {
                string t = "";
                i++;
                while(i < len && s[i] != '"')
                {
                    t += s[i];
                    i++;
                }
                st.insert(t);
            }
        }
        ss.insert(st);
    }
    cout << ss.size() << endl;
    return 0;
}