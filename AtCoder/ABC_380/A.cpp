#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    while(n)
    {
        int temp = n%10;
        n /= 10;
        if(temp == 1)
        {
            a++;
        }
        else if(temp == 2)
        {
            b++;
        }
        else if(temp == 3)
        {
            c++;
        }
    }
    if(a==1 && b==2 && c==3)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}