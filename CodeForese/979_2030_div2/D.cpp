#include <bits/stdc++.h>
using namespace std;
void solve()
{
    // int n, q;
    // cin >> n >> q;
    // vector<int> perm(n);
    // for(int i = 0; i < n; i++)
    // {
    //     cin >> perm[i];
    // }
    // for(int i = 0; i < n; i++)
    // {
    //     perm[i]--;
    // }
    // vector<int> invperm(n);
    // for(int i = 0; i < n; i++)
    // {
    //     invperm[perm[i]] = i;
    // }
    // vector<int> diffArr(n);
    // for(int i = 0; i < n; i++)
    // {
    //     diffArr[min(i, invperm[i])]++;
    //     diffArr[max(i, invperm[i])]--;
    // }
    // for(int i = 1; i < n; i++)
    // {
    //     diffArr[i] += diffArr[i-1];
    // }
    // string s;
    // cin >> s;
    // set<int> problems;
    // for(int i = 0; i < n-1; i++)
    // {
    //     if(s[i] == 'L' && s[i+1] == 'R' && diffArr[i] != 0)
    //     {
    //         problems.insert(i);
    //     }
    // }
    // while(q--)
    // {
    //     int x;
    //     cin >> x;
    //     x--;
    //     if(s[x] == 'L')
    //     {
    //         s[x] = 'R';
    //     }
    //     else
    //     {
    //         s[x] = 'L';
    //     }
    //     if(s[x-1] == 'L' && s[x] == 'R' && diffArr[x-1] != 0)
    //     {
    //         problems.insert(x-1);
    //     }
    //     else
    //     {
    //         problems.erase(x-1);
    //     }
    //     if(s[x]=='L' && s[x+1] == 'R' && diffArr[x] != 0)
    //     {
    //         problems.insert(x);
    //     }
    //     else
    //     {
    //         problems.erase(x);
    //     }
    //     if(problems.size())
    //     {
    //         cout << "NO" << endl;
    //     }
    //     else
    //     {
    //         cout << "YES" << endl;
    //     }
    // }


    //jiangly`s code
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for(int i = 1; i < n; i++)
    {
        p[i] = max(p[i], p[i-1]);
    }
    vector<bool> bad(n);//初始化为false
    for(int i = 1; i < n; i++)
    {
        //这里实际上也是检查p1~pi
        //因为之前我们已经对p数组进行了改动，使得数组中的pi均为之前的最大值
        //所以只要p[i-1] != i,在p1~pi中的某个数字是需要移动到右边的
        if(p[i-1] != i)
        {
            bad[i] = true;
        }
    }
    //另一种写法
    // for(int i = 1; i <= n; i++)
    // {
    //     int in;
    //     cin >> in;
    //     maxx = max(in, maxx);
    //     bad[i] = (maxx == i);  //如果maxx不是i，说明当前p1~pi中有比i大的数，则p1~pi肯定不会涵盖1~i的所有元素
    // }

    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(bad[i] && s.substr(i-1, 2) == "LR")//如果遇到"LR"则说明对应的i左边的数字是无法移动到右边的
        {
            cnt++;
        }
    }
    for(int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        x--;
        if(bad[x] && s.substr(x-1, 2) == "LR")
        {
            cnt--;
        }
        if(bad[x+1] && s.substr(x, 2) == "LR")
        {
            cnt--;
        }
        if(s[x] == 'L')
        {
            s[x] = 'R';
        }
        else
        {
            s[x] = 'L';
        }
        if(bad[x] && s.substr(x-1, 2) == "LR")
        {
            cnt++;
        }
        if(bad[x+1] && s.substr(x, 2) == "LR")
        {
            cnt++;
        }
        if(cnt == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}