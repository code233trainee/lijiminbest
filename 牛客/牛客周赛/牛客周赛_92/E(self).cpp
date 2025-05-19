#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    int idx = 1;
    vector<int> v(1, 1);
    unordered_map<int, int> L, R;
    int S = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        S += a;
        vector<int> next;
        if(i == 0)
        {
            continue;
        }
        for(auto &z : v)
        {
            if(a >= 2)
            {
                L[z] = ++idx;
                next.push_back(idx);
                R[z] = ++idx;
                next.push_back(idx);
                a -= 2;
            }
            else if(a >= 1)
            {
                L[z] = ++idx;
                next.push_back(idx);
                a--;
            }
            else
            {
                break;
            }
        }
        v = next;
    }
    cout << "1\n";
    for(int i = 1; i <= S; i++)
    {
        if(!L.count(i))
        {
           L[i] = -1;
        }
        if(!R.count(i))
        {
            R[i] = -1;
        }
        cout << L[i] << " " << R[i] << "\n";
    }
}
int main()
{
    solve();
    return 0;
}