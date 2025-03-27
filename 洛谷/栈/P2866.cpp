#include <bits/stdc++.h>
using namespace std;
const int N = 8e4 + 10;
int n, stk[N], top = 0;
long long ans = 0;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        while(top > 0 && h >= stk[top])
        {
            top--;
        }
        top++;
        stk[top] = h;
    }   
    cout << ans << "\n";
    return 0;
}