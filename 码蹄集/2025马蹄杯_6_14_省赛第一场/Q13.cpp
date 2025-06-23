#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    deque<int> dq;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dq.push_back(x);
    }   
    while(q--)
    {
        int k;
        cin >> k;
        if(k == 1)
        {
            int a = *dq.begin();
            dq.pop_front();
            dq.push_back(a);
        }
        else
        {
            int a = dq.back();
            dq.pop_back();
            dq.push_front(a);
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << dq[i] << " ";
    }
    return 0;
}