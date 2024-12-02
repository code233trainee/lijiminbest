#include <bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> Q(n), R(n);
    for(int i = 0; i < n; i++)
    {
        cin >> Q[i] >> R[i];
    }
    int q;
    cin >> q;
    while(q--)
    {
        int t ,d;
        cin >> t >> d;
        t--;
        int x = d % Q[t];
        int diff = R[t] - x;
        if(diff < 0)
        {
            diff += Q[t];
        }
        cout << d + diff << endl;
    }
}