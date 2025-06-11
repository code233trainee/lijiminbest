#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node{
    ll l, r, val;
    bool operator<(const Node &n) const{
        if(l == n.l) return r < n.r;
        return l < n.l;
    }
};
int main()
{
    set<Node> sn;
    sn.insert({0, 200000, 0});
    map<ll, ll> m;
    m[0] = 2e5;

    ll q;
    cin >> q;
    while(q--)
    {
        ll l, r, x;
        cin >> l >> r >> x;

        Node p = {l, 200000, 0};
        auto L = sn.lower_bound(p);
        L--;
        ll l1 = L->l, r1 = L->r, val1 = L->val;

        Node k = {r + 1, 200000, 0};
        auto R = sn.lower_bound(k);
        R--;
        ll l2 = R->l, r2 = R->r, val2 = R->val;

        vector<Node> del;
        for(auto it = L; ; it++)
        {
            del.emplace_back(*it);
            if(it == R)
            {
                break;
            }   
        }
        for(auto &d : del)
        {
            ll l = d.l;
            ll r = d.r;
            ll val = d.val;
            m[val] -= r - l + 1;
            if(m[val] == 0)
            {
                m.erase(val);
            }
            sn.erase(d);
        }
        if(l1 < l)
        {
            sn.insert({l1, l-1, val1});
            m[val1] += (l - l1);
        }
        if(r < r2)
        {
            sn.insert({r + 1, r2, val2});
            m[val2] += (r2 - r);
        }
        sn.insert({l, r, x});
        m[x] += r - l + 1;

        cout << m.size() << "\n";
    }
    return 0;
}