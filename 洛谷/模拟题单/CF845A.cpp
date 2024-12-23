#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(2*n+1);
    for(int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[(n*2)/2] == a[(n*2)/2 + 1])
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
    return 0;
}