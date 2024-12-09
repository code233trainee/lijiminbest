#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<string> Q(n), Ans(n);
    for(int i = 0; i < n; i++)
    {
        cin >> Q[i] >> Ans[i];
    }
    int k = 0;
    while(q--)
    {
        string qs;
        cin >> qs;
        for(k = 0; k < n; k++)
        {
            if(qs == Q[k])
            {
                break;
            }
        }
        for(int i = 0; i < 4; i++)
        {
            string ans;
            cin >> ans;
            //注意输入条件
            //不能找到答案就返回
            //需要四个选项输入完成，不然就乱了
            if(ans == Ans[k])
            {
                cout << char('A' + i) << endl;
            }
        }
    }
}