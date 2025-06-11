#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
    mutable int num, cnt;
    node() = default;
    node(int A, int B){
        num = A;
        cnt = B;
    }
    const bool operator<(const node &x) const{
        return cnt == x.cnt ? num < x.num : cnt < x.cnt;
    }
};
set<node> s;
set<int> ans;
int a[2004];
int cnt[2000006];
void add(int val){
    auto it = s.lower_bound(node(val, cnt[val]));
    cnt[val]++;
    if(val == it -> num){
        s.erase(it);
        s.insert(node(val, cnt[val]));
    } else {
        s.insert(node(val, 1));
    }
}
void del(int val){
    auto it = s.lower_bound(node(val, cnt[val]));
    cnt[val]--;
    s.erase(it);
    if(cnt[val] >= 1)
    {
        s.insert(node(val, cnt[val]));
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            del(a[i]);
            add(a[i] + 1);
            del(a[j]);
            add(a[j] - 1);
            ans.insert(s.rbegin()->num);
            del(a[i] + 1);
            add(a[i]);
            del(a[j] - 1);
            add(a[j]);
        }
    }
    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}