#include <bits/stdc++.h>
using namespace std;
void befor(string mid, string after)
{
    if(mid.size() > 0)
    {
        char ch = after[after.size() - 1];
        cout << ch;
        int k = mid.find(ch);
        befor(mid.substr(0, k), after.substr(0, k));
        befor(mid.substr(k+1), after.substr(k, mid.size() - k - 1));
    }
}
int main()
{
    string mid, after;
    cin >> mid >> after;
    befor(mid, after);
    cout << endl;
    return 0;
}