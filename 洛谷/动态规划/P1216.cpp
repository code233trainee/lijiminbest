#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(1100));
    for(int i = 1; i <= n; i++)
    {
        if(i == 1)
        {
            int x;
            cin >> x;
            a[1][1] = x;
        }
        else
        {
            int cnt = i;
            int j = 1;
            while(cnt--)
            {
                int num;
                cin >> num;
                a[i][j] = max(a[i-1][j], a[i-1][j-1]) + num;
                j++;
            }
        }

    }
    int mx = *(max_element(a[n].begin(), a[n].end()));
    cout << mx << endl;
    return 0;
}