#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 树状数组模板
class BIT{
public:
    BIT(ll size) : size_(size), tree_(size + 1, 0) {}

    //单点更新
    void update(ll index, ll delta)
    {
        // lowbit: i & -i
        for(ll i = index + 1; i <= size_; i += (i & -i))
        {
            tree_[i] += delta;
        }
    }

    //单点查询(前缀和)
    ll query(ll index)
    {
        ll sum = 0;
        for(ll i = index + 1; i > 0; i -= (i & -i))
        {
            sum += tree_[i];
        }
        return sum;
    }

    //区间查询
    ll queryRange(ll left, ll right)
    {
        return query(right) - query(left - 1);
    }
private:
    ll size_;
    vector<ll> tree_;
};

struct Query{
    ll  k1, k2, id;

    bool operator<(const Query & q) const{
        return k1 < q.k1;
    }
};
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> a(n + 1);
    vector<ll> v;
    map<ll, ll> mp;

    // y < x + k1 => x - y > -k1
    // y < -x + k2 => x + y < k2
    for(ll i = 1, x, y; i <= n; i++)
    {
        cin >> x >> y;
        //转化坐标
        ll X = x - y;
        ll Y = x + y;
        a[i] = {X, Y};
        v.emplace_back(X);
        v.emplace_back(Y);
    }

    vector<Query> Q(q);
    for(ll i = 0; i < q; i++)
    {
        cin >> Q[i].k1 >> Q[i].k2;
        Q[i].id = i;
        Q[i].k1 *= -1;
        v.emplace_back(Q[i].k1);
        v.emplace_back(Q[i].k2);
    }

    //离散化
    sort(v.begin(), v.end());
    ll idx = 1;
    for(ll i = 1; i < v.size(); i++)
    {
        if(i > 0 && v[i] > v[i-1])
        {
            idx++;
        }
        mp[v[i]] = idx;
    }

    //使用离散化后的值
    for(ll i = 1; i <= n; i++)
    {
        auto & [x, y] = a[i];
        x = mp[x];
        y = mp[y];
    }
    for(auto &[k1, k2, _] : Q)
    {
        k1 = mp[k1];
        k2 = mp[k2];
    }

    BIT bit((n + q) * 2 + 1);
    for(ll i = 1; i <= n; i++)
    {
        auto [x, y] = a[i];
        //本质上y是(x + y),需要小于k2
        bit.update(y, 1);
    }
    sort(a.begin() + 1, a.end());
    sort(Q.begin(), Q.end());

    vector<ll> ans(q);
    ll i = 1;
    for(auto &[k1, k2, id] : Q)
    {
        while(i <= n && a[i].first <= k1)
        {
            //不符合的
            bit.update(a[i].second, -1);
            i++;
        }
        ans[id] = bit.query(k2 - 1);
    }

    for(ll i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}