#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //复制一份
    vector<int> as = a;
    sort(as.begin(), as.end());
    //unique()函数会去除范围内的重复元素，并且压缩数组，使得重复的数组被“移到末尾”
    //但不是正真的移到末尾，是使得末尾的"重复"元素变为无效元素(可能是任何值)
    //返回的是一个迭代器，指向不重复元素的末尾
    as.resize(unique(as.begin(), as.end()) - as.begin());
    int cnt = int(as.size());
    for(int i = 0; i < n; i++)
    {
        //lower_bound(),在范围内查找指定的值，并返回指向该元素的迭代器，如果找不到则会返回大于该元素的第一个迭代器
        a[i] = int(lower_bound(as.begin(), as.end(), a[i]) - as.begin());//减去begin得到索引值
    }
    //以上所做的工作主要是去除了数组中的重复元素，并且将重复元素的位置标记在原数组中(a)
    cin >> m;
    while(m--)
    {
        string s;
        cin >> s;
        if(int(s.size()) != n)
        {
            cout << "NO\n";
            continue;
        }
        string mp(cnt, ' ');
        bool ok = true;
        for(int i = 0; i < n; i++)
        {
            if(mp[a[i]] == ' ')
            {
                mp[a[i]] = s[i];
            }
            else
            {
                ok &= (mp[a[i]] == s[i]);
            }
        }
        sort(mp.begin(), mp.end());
        for(int i = 0; i < cnt - 1; i++)
        {
            ok &= (mp[i] != mp[i + 1]);
        }//确保元素不重复
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}