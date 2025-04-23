#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll norm = 0, rev = 0;
    ll q;
    cin >> q;
    ll tot = 0;
    ll n = 0;
    deque<ll> qNorm, qRev;
    ll p = 0;
    while(q--) {
        ll s;
        cin >> s;
        if(s == 1) {
            ll last = qNorm.back();
            qNorm.pop_back();
            qNorm.push_front(last);
            norm += (tot - last);
            norm -= last * n;
            norm += last;

            last = qRev.front();
            qRev.pop_front();
            qRev.push_back(last);
            rev -= (tot - last);
            rev += last * n;
            rev -= last;
        } else if (s == 2) {
            swap(rev, norm);
            swap(qNorm, qRev);
        } else if (s == 3) {
            n++;
            ll k;
            cin >> k;
            qNorm.push_back(k);
            qRev.push_front(k);
            norm += k * n;
            rev += tot;
            rev += k;
            tot += k;
        }
        cout << norm << "\n";
    }
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}