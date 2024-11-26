#include<iostream>
using namespace std;
bool guess(int i)
{
    int k = 1;
    int n;
    while(i >= 10)
    {
        n = i % 10;
        i /= 10;
        if(k % 2 == 1)
        {
            if(n % 2 == 1)
            {
                k++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(n % 2 == 0)
            {
                k++;
            }
            else
            {
                return false;
            }
        }
    }
    // return true;
    if(k % 2 == 1)
    {
        if(i % 2 == 1 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(i % 2 == 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
int main()
{
    int count = 0;
    int n = 0;
    cin >> n;
    for(int i = n-1; i > 0; i--)
    {
        if(guess(i))
        {
            count++;
            // cout << i << endl;
        }
    }
    cout << count;
    return 0;
}