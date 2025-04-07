#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        string s, t;
        cin >> s >> t;
        int k;
        cin >> k;
        
        int n = s.size();
        int tLen = t.size();
        bool valid = true;
        int pos = 0; // 当前 t 的指针
        
        // 前 k-1 步：由于 i < k 时，规则无法触发，输出必为 s[i]
        for (int i = 0; i < k - 1 && i < n; i++){
            if(pos >= tLen || t[pos] != s[i]){
                valid = false;
                break;
            }
            pos++;
        }
        
        map<string, string> ma;
        
        // 对于 i 从 k 到 n，i 的 0-index 对应 i=k-1...n-1
        for (int i = k - 1; i < n && valid; i++){
            // u 为当前步对应的长度为 k 的后缀
            string u = s.substr(i - k + 1, k);
            if(ma.find(u) != ma.end()){
                // 若 u 已在映射中，则当前步输出固定为 ma[u]
                string out = ma[u];
                if(out == ""){
                    // 输出为空，不消耗 t 中字符
                } else {
                    if(pos >= tLen || t[pos] != out[0]){
                        valid = false;
                        break;
                    }
                    pos++;  // 消耗 1 个字符
                }
            } else {
                // 尚未为 u 指定规则，则默认输出为 s[i]
                if(pos < tLen && t[pos] == s[i]){
                    // 默认符合 t，什么也不做
                    pos++;
                } else {
                    // 若 t 当前字符（如果有）与 s[i]不同，则为 u 设定覆盖规则
                    if(pos < tLen){
                        ma[u] = string(1, t[pos]);
                        pos++;
                    } else {
                        // t 已结束，则我们希望当前步输出空
                        ma[u] = "";
                    }
                }
            }
        }
        
        // 模拟结束后，必须刚好“消费完” t，且映射中规则数不超过 50
        if(!valid || pos != tLen || ma.size() < 1 || ma.size() > 50){
            // 无法构造出满足条件的映射集合，输出 0 表示（特殊判题下无解情况）
            cout << 0 << "\n";
        } else {
            cout << ma.size() << "\n";
            for(auto &p : ma){
                // 格式严格为 (λ,γ)，其中 λ 为 p.first, γ 为 p.second（可能为空）
                cout << "(" << p.first << "," << p.second << ")\n";
            }
        }
    }
    return 0;
}
