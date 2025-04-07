#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        // 模拟“消除”操作：利用栈思想
        int top = -1;  // 使用数组模拟栈，下标 -1 表示空栈
        // 为了不频繁使用容器，我们可以用字符串本身做栈（也可以用 vector<char>）
        // 这里我们直接用 s 作为辅助栈，top 表示栈顶下标
        // 注意：原串 s 的长度为 n，但我们不会改变它的长度，仅用作临时保存
        for (int i = 0; i < n; i++){
            char c = s[i];
            if (top >= 0 && s[top] == c) {
                // 与栈顶相同，模拟消除操作：弹出栈顶
                top--;
            } else {
                // 不相同，则“入栈”
                top++;
                s[top] = c;
            }
        }
        int L = top + 1; // 最终栈的长度
        // 最少修改次数 = L / 2 （整数除法）
        cout << L / 2 << "\n";
    }
    return 0;
}
