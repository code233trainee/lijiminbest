#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll total = 0;
    set<ll> ms;
    set<int,std::greater<int>> mss;

    map<ll, ll> ma;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        ms.insert(a[i]);
        ma[a[i]]++;
    }
    // std::less<int> callable_obj;
    // bool b = callable_obj(1,2);
    // auto ittt = a.begin();
    // *ittt = 1;
    while(k--)
    {
        auto it = ms.rbegin();
        // auto it = ms.begin();
        // *it = 1;
        ms.insert(*it/2);
        ma[*it]--;
        ma[*it/2]++;
        if(ma[*it] <= 0)
        {
            ms.erase(*it);
        }
    }
    for(auto z : ms)
    {
        total += z * ma[z];
    }
    cout << total << endl;
    return 0;
}