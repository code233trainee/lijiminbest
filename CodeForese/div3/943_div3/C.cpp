#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int s = 1000;
    // (a+b) mod a=b, 只当a大于b时成立
    //所以我们直接
    cout << s << " ";
    for(int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        //我们只需要保证后面的元素严格大于前一个元素就可以
        s += x;
        cout << s << " ";
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}