#include <bits/stdc++.h>
using namespace std;
void solve()
{

}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    if(n&1)
    {
        if(n==1 && s[0] == '/')
        {
            cout << "Yes" << endl;
            return 0;
        }
        bool isok = true;
        for(int i = 0; i <= (n+1)/2 - 2; i++)
        {
            if(s[i] == '1')
            {
                continue;
            }
            else
            {
                isok = false;
            }
        }
        if(s[(n+1)/2 - 1] != '/')
        {
            isok = false;
        }
        for(int i = (n+1)/2; i < n; i++)
        {
            if(s[i] == '2')
            {
                continue;
            }
            else
            {
                isok = false;
            }
        }
        if(isok)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else
    {
        cout << "No" << endl;
    }
}