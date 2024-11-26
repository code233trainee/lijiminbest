#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<char, int> m;
    m['P'] = 0;
    m['B'] = 0;
    while(n--)
    {
        char c;
        int a;
        cin >> c >> a;
        m[c] += a;
        if(c == 'B')
        {
            if(m['B'] > m['P'])
            {
                m['P'] = 0;
                m['B'] = 0;
                cout << "YES" << '\n';
            }
            else
            {
                m['P'] -= m['B'];
                m['B'] = 0;
                cout << "NO" << '\n';
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    // int T;
	// cin>>T;
	// int cur=0;
	// while(T--){
	// 	char c;
	// 	int x;
	// 	cin>>c>>x;
	// 	if(c=='B'){
	// 		puts(x>cur?"YES":"NO");
	// 		cur-=min(cur,x);
	// 	}
	// 	else cur+=x;
	// }
    // 这是一个更简洁的代码
    return 0;
}