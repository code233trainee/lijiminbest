#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;

    while(n--)
    {
        int t = 0;
        cin >> t;
        char m;
        vector<int> num(t);
        for(int i = 0; i < t; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cin >> m;
                if(m == '#')
                {
                    num[i] = j+1;
                }
            }
        }
        for(int k = t - 1; k >= 0; k--)
        {
            cout << num[k] << " ";
        }
        cout << endl;
    }
    return 0;
}