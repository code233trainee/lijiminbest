#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    int q;cin>>q;  
    vector<vector<int>> pos(26);
    for(int i = 0; i < s.size(); i++) 
        pos[s[i]-'a'].push_back(i);

    while(q--) {
        int l, r; char x, y;
        cin >> l >> r >> x >> y;
        auto& vec = pos[x-'a'];
        auto it = lower_bound(vec.begin(), vec.end(), l-1);
        while(it != vec.end() && *it <= r-1) {
            s[*it] = y;
            pos[y-'a'].push_back(*it); // 维护新位置
            it = vec.erase(it);        // 删除旧位置
        }
    }
    cout << s << endl;
    return 0;
}