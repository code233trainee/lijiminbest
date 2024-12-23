#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, q, suma = 0, sumb = 0, x, del1, del2, i;
    bool flag;
    cin >> n >> m >> q;
    map<ll, ll> mapa, mapb;
    vector<ll> a(n), b(m);
    for(auto &z : a)
    {
        cin >> z;
        suma += z;
        mapa[z] = 1;
    }
    for(auto &z : b)
    {
        cin >> z;
        sumb += z;
        mapb[z] = 1;
    }
    // B=(a1+a2+a3+a4+…)⋅(b1+b2+b3+…)
    // B=SumA⋅SumB
    // X=B−(bi⋅SumA+aj⋅SumB−aj⋅bi)
    // X=(SumB−bi)⋅(SumA−aj)
    while(q--)
    {
        cin >> x;
        flag = false;
        // 如果 x = 36，那么它的除数有 1、2、3、4、6、9、12、18 和 36。
        // 我们可以观察到：当 d = 2 时，x / d = 18；当 d = 3 时，x / d = 12，以此类推。
        // 对于每一个小的除数 d，它都有一个对应的大的除数 x/d。
        // 只要遍历 1 到 sqrt(abs(x))，我们就能找到所有的除数
        for(i = 1; i <= sqrt(abs(x)); i++)
        {
            if(x%i != 0)
            {
                continue;
            }
            del1 = i;
            del2 = x/i;
            flag |= mapb[sumb - del1] && mapa[suma - del2];
            flag |= mapb[sumb - del2] && mapa[suma - del1];
            del1 *= -1;
            del2 *= -1;
            flag |= mapb[sumb - del1] && mapa[suma - del2];
            flag |= mapb[sumb - del2] && mapa[suma - del1];
        }
        if(flag)
        {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}