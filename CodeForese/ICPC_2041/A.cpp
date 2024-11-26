#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum = 0;
    for(int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        sum+=temp;
    }
    cout << 15 - sum << endl;
    return 0;
}