#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    
    int n;
    cin >> n;
    map<int, int> m;
    for(int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        if(m.count(t))
        {
            cout << m[t] << " ";
            m[t] = i;   
        }
        else
        {
            m[t] = i;
            cout << -1 << " ";
        }
    }
}