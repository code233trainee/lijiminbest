#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
bool solve(int a, int b, int c)
{
    set<int> se;
    se.insert(a%10);
    a /= 10;
    se.insert(a%10);
    a /= 10;
    se.insert(a);
    se.insert(b%10);
    b /= 10;
    se.insert(b%10);
    b /= 10;
    se.insert(b);
    se.insert(c%10);
    c /= 10;
    se.insert(c%10);
    c /= 10;
    se.insert(c);
    se.erase(0);
    if(se.size() == 9)
    {
        return true;
    }
    return false;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool  isok = false;
    for(int i = 1; i <= 999; i++)
    {
        int a1 = i * a;
        int a2 = i * b;
        int a3 = i * c;
        if(solve(a1, a2, a3) && a2 < 1000 && a3 < 1000)
        {
            cout << a1 << " " << a2 << " " << a3 << endl;
            isok = true;
        }
    }
    if(!isok)
    {
        cout << "No!!!" << endl;
    }
    return 0;
}