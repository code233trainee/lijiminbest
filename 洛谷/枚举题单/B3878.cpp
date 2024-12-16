#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n-k+1; i++)
    {
        int sum = 0;
        for(int j = i; j < k + i; j++)
        {
            sum += j;
        }
        int temp = sqrt(sum);
        if(temp*temp == sum)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}