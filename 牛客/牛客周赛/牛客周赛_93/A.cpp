#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(pow(2, n) > pow(n, 3))
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "A" << endl;
    }
    return 0;
}