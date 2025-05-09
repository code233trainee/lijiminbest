#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 计算字符串 s 的前缀函数
vector<int> computePrefix(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    // 多行输入，直到EOF
    while(getline(cin, s)) {
        if(s.empty()) continue;  // 跳过空行
        
        // 计算 s 的反转 rev
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // 构造辅助串 t = s + "#" + rev
        string t = s + "#" + rev;
        vector<int> pi = computePrefix(t);
        
        // 最长回文后缀的长度
        int L = pi[t.size() - 1];
        
        // 未覆盖部分为 s.substr(0, s.size()-L)，其反转后添加到 s 后面
        string missing = s.substr(0, s.size() - L);
        reverse(missing.begin(), missing.end());
        
        string ans = s + missing;
        cout << ans << "\n";
    }
    
    return 0;
}
