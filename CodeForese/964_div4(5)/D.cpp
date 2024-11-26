// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int n = 0;
//     string s, v;
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         cin >> s >> v;
//         for(int j = 0; j < v.length(); j++)
//         {
//             for(int k = 0; k < s.length(); k++)
//             {
//                 if( (v[j] == s[k]) || (s[k] == '?'))
//                 {
//                     if((s[k] == '?'))
//                     {
//                         s[k] = v[j];
//                     }
//                     break;
//                 }
//             }
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

bool replaceAndMatch(string &s, string v) {
    int j = 0;  // 指向 v 的指针
    for (int i = 0; i < s.length(); i++) {
        if (j < v.length() && (s[i] == v[j] || s[i] == '?')) {
            s[i] = v[j];  // 用 v[j] 替换 '?'，或者保持 s[i] 不变
            j++;  // 匹配成功，指针 j 向右移动
        } 
    }
    return j == v.length();  // 检查是否完全匹配了 v
}

void replaceRemainingQuestions(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '?') {
            s[i] = 'a';  // 将未使用的 '?' 替换为字母 'a'
        }
    }
}

int main() {
    int n = 0;
    string s, v;
    cin >> n;  // 输入测试用例数量
    for (int i = 0; i < n; i++) {
        cin >> s >> v;
        if (replaceAndMatch(s, v)) {
            replaceRemainingQuestions(s);  // 将未使用的 '?' 替换掉
            cout << "YES" << endl;
            cout << s << endl;  // 输出替换后的 s
        } else {
            cout << "NO" << endl;  // 无法匹配 v
        }
    }
    return 0;
}
