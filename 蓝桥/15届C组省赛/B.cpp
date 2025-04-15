#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll mxK = 1;
    ll K = 1;
    ll lastTime = 0;
    while(true)
    {
        char c1, c2;
        ll time;
        cin >> c1 >> c2 >> time;
        if(c1 == '1' && c2 == '1' && time == 1)
        {
            break;
        }
        if(c1 == c2 && time - lastTime <= 1000)
        {
            lastTime = time;
            K++;
        }
        else
        {
            mxK = max(mxK, K);
            lastTime = time;
            K = 1;
        }
    }
    cout << mxK;
    return 0;
}