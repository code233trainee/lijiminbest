#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    vector<int> sm(n+1);
    for(int i = 1; i <= n; i++)
    {
        sm[i] = sm[i-1] + (s[i] == '0');
    }
    int ans = n - sm[n];
    int mn = n;
    for(int i = n; i >= 1; i--)
    {
        mn = min(mn, n - i - sm[n] + 2*sm[i]);
        ans = min(ans, mn + i - 1 - 2*sm[i-1]);
    }
    cout << ans << endl;
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


// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
// 	int n;
// 	cin>>n;
// 	string s;
// 	cin>>s;
// 	vector<int> a;
// 	int sum=0;
// 	for(int i=0;i<s.size();i++){
// 		if(s[i]=='1')sum++;
// 		if(s[i]=='1')a.push_back(-1);
// 		else a.push_back(1);
// 	}
// 	int res=0,cnt=0;
// 	for(int i=0;i<n;i++){
// 		cnt=min(a[i],cnt+a[i]);
// 		res=min(res,cnt);
// 	}
// 	cout<<sum+res<<'\n';
// }
// signed main() {
// 	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// 	int T = 1;
// 	cin >> T;
// 	while(T --){
// 		solve();
// 	}
// 	return 0;
// }