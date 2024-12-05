#include <bits/stdc++.h>
using namespace std;
int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t = 0;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        set<int> e;
        //lambda表达式只捕获同一个作用域的(需要有局部上下文)
        auto Updata = [&](int i){//按引用传递外部参数
            if(i >= 0 && i <= n - 3)
            {
                if(s.substr(i, 4) == "1100")//substr((index), (count)),返回的是一个子串
                {
                    e.insert(i);
                }
                else
                {
                    e.erase(i);
                }
            }
        };
        for(int i = 0; i <= n - 4; i++)
        {
            Updata(i);
        }
        int q = 0;
        cin >> q;
        while(q--)
        {
            //字符‘0’的ascll码是48，字符‘1’的ascll码是49
            int i, c;
            cin >> i >> c;
            i--;
            s[i] = char('0' + c);
            for(int j = i - 3; j <= i; j++)//每次查询只关注可能会受到影响的位置
            {
                Updata(j);
            }
            cout << (e.empty() ? "NO" : "YES") << endl;
        }
    }
}