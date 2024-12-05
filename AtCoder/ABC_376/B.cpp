#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> n >> t;
    int ans = 0;
    int a[2] = {0, 1};
    auto work = [&](int i, int x){
        //注意这里的判断
        if(abs(a[!i] - a[i]) + abs(a[!i] - x) == abs(a[i] - x))
        {
            ans += n - abs(a[i] - x);
        }
        else
        {
            ans += abs(a[i] - x);
        }
        a[i] = x;
    };
    for(int i = 0; i < t; i++)
    {
        char c;
        int x;
        cin >> c >> x;
        x--;
        work(c == 'L' ? 0 : 1, x);
    }
    cout << ans << endl;
}