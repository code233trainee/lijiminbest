#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> cand(n+1);
    vector<int> a(n+1);
    vector<int> b(n+2);
    for(int i = 1; i <= n; i++)
    {
        cin >> cand[i];
        a[i] = cand[i] + a[i-1];
    }
    if(n == 1)
    {
        cout << "1 0\n";
        return 0;
    }
    for(int i = n; i >= 1; i--)
    {
        b[i] = b[i+1] + cand[i];
    }
    // while(l <= r)
    // {
    //     if(a[l] < b[r])
    //     {
    //         l--;
    //     }
    //     else if(a[l] == b[r])
    //     {
    //         l++;
    //     }
    //     else
    //     {
    //         r--;
    //     }
    // }

    //仔细思考
    int cnta = 0, cntb = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] <= b[i])
        {
            cnta++;
        }
        else
        {
            cntb++;
        }
    }
    cout << cnta << " " << cntb << "\n";
    return 0;
}