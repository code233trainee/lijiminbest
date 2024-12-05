#include <bits/stdc++.h>
using namespace std;
int a[200005];
map<pair<int, int>, int> mp, mp2, mp3;
map<tuple<int, int, int>, int> mp4;
void solve()
{
    int n;
    cin >> n;
    long long ans = 0;
    mp.clear();
    mp2.clear();
    mp3.clear();
    mp4.clear();
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n-1; i++)
    {
        //题目要求是有两个元素相同一个元素不同的三元对的数量
        ans += mp[make_pair(a[i], a[i+1])];
        ans += mp2[make_pair(a[i+1], a[i+2])];
        ans += mp3[make_pair(a[i], a[i+2])];
        mp[make_pair(a[i], a[i+1])]++;
        mp2[make_pair(a[i+1], a[i+2])]++;
        mp3[make_pair(a[i], a[i+2])]++;
        //所以如果是第一次出现的我们需要先记录然后再加1
    }
    for(int i = 2; i < n; i++)
    {
        //去除三个元素都相同的情况
        ans -= mp4[make_tuple(a[i-1], a[i], a[i+1])]*3;
        mp4[make_tuple(a[i-1], a[i], a[i+1])]++;
    }
    cout << ans << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}