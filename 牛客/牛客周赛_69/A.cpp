#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int c = abs(a - b);
    int d = max(a, b) + c;
    cout << d << endl;
}