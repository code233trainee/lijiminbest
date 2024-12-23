#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    for(int i = 1; i <= 1666; i++)
    {
        if(i%3 != 0 && i%10 != 3)
        {
            a.push_back(i);
        }
    }
    int n;
    cin >> n;
    while(n--)
    {
        int ind;
        cin >> ind;
        cout << a[--ind] << "\n";
    }
    return 0;
}