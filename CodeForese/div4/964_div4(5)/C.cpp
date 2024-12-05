//accepted


#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int a, b, c, d, e;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        int time = 0;
        bool isOk = false;
        int f = 0;
        bool output = false;
        for(int j = 0; j < a; j++)
        {
            cin >> d >> e;
            if(!output)
            {
                if(d != 0 && j == 0)
                {
                    time = d - 0;
                }
                else if (j > 0)
                {
                    time = d - f;
                }
                if(time >= b)
                {
                    cout << "YES" << endl;
                    isOk = true;
                    output = true;
                }
                f = e;
                if ((time < b) && (j == (a - 1)))
                {
                    time = c - f;
                    if(time >= b)
                    {
                        cout << "YES" << endl;
                        isOk = true;
                        output = true;
                    }
                }
            }
            
        }
        if(!isOk)
        {
            cout << "NO" << endl;
        }
    }
}