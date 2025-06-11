#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> um;
    vector<int> G;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        um[x] = i;
    }
    for(int i = 0; i < n; i++)
    {
        if(abs(i - um[a[i]]) > 0)
        {
            G.push_back(abs(i - um[a[i]]));
        }
    }
    if(!G.size())
    {
        cout << "0\n";
    }
    else
    {
        sort(G.begin(), G.end());
        int g = G[0];
        for(int i = 1; i < G.size(); i++)
        {
            g = gcd(g, G[i]);
        }
        for(int i = 1; i <= g; i++)
        {
            if(g % i == 0)
            {
                cout << i << "\n";
            }
        }
    }
    return 0;
}