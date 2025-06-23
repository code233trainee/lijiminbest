#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    vector<ll> a(110);
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= 100; i++)
    {
        a[i] = (a[i-1] + a[i-2]);
        cout << "第" << i+1 << "项是："<< a[i] << endl;
    }
    return 0;
}