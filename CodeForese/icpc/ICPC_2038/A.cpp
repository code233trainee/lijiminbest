#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i] / b[i];
    }

    if(sum < k)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "0" << " ";
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            sum -= a[i]/b[i];
            int c = max(0LL, (k - sum));
            k -= c;
            cout << c << " \n"[i == n - 1];
        }
    }
}