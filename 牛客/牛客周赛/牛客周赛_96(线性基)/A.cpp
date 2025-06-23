#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int x = 0;
    cin >> x;
    int A = (x - 5) * 5;
    int B = x * 4;
    if(A == B) {
        cout << 0 << endl;
    } else if(A < B) {
        cout << 5 << endl;
    } else {
        cout << 8 << endl;
    }
    return 0;
}