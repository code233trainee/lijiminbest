#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    if(n&1)
    {
        if(n < 27)
        {
            cout << "-1" << "\n";
        }
        else
        {
            //奇数需要构造一个x<y<z,并且z-x = (z - y) + (y - x)
            //5^2 = 4^2 + 3^2;
            cout<<"1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
            for (int i=14;i<=n/2;i++) 
            {
                cout<<i<<" "<<i<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        for(int i = 1; i <= n/2; i++)
        {
            cout << i << " " << i << " ";
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}