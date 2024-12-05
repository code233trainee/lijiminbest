#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> st(n+1), en(n+1);
    for(int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        st[l]++;
        en[r]++;
    }
    //注意这里的处理，类似于累加？只不过所有元素初始化为0
    for(int i = 0; i < n; i++)
    {
        st[i+1] += st[i];
    }
    for(int i = 0; i < n; i++)
    {
        en[i+1] += en[i]; 
    }

    int most = 0;
    int robert = 0;
    int mrs = 0;
    int least = INT_MAX;
    for (int i=d;i<=n;i++){
        int cur = st[i] - en[i-d];
        if (cur > most) most = cur, robert = i-d+1;
        if (cur < least) least = cur, mrs = i-d+1;
    }
    cout << robert << " " << mrs << endl;
}

int main()
{
    //高效处理输入输出
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}