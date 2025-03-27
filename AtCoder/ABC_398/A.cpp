#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int cnt = 1 + !(n % 2);
    int cnt_ = n/2 - !(n % 2);
    for(int i = 0; i < cnt_; i++) cout << '-';
    for(int i = 0; i < cnt; i++) cout << '=';
    for(int i = 0; i < cnt_; i++) cout << '-';
    return 0;
}