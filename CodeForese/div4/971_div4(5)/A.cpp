#include <iostream>
using namespace std;

int miniment (int a, int b)
{
    int c = a;
    if(a == b) return 0;
    return (c - a) + (b - c);
}

int main()
{
    int n = 0;
    cin >> n;
    while(n--)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << miniment(a, b) << '\n';
    }
}