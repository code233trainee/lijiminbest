#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    // if(n == 1)
    // {
    //     cout << "A Problem" << endl;
    // }
    // else if(n == 2)
    // {
    //     cout << "A+B Problem" << endl;
    //     cout << "B+A Problem" << endl;
    // }
    // else if(n == 3)
    // {
    //     cout << "A+B+C Problem" << endl;
    //     cout << "A+C+B Problem" << endl;
    //     cout << "B+A+C Problem" << endl;
    //     cout << "B+C+A Problem" << endl;
    //     cout << "C+A+B Problem" << endl;
    //     cout << "C+B+A Problem" << endl;
    // }
    // else if(n == 4)
    // {
    //     cout << "A+B+C+D Problem" << endl;
    //     cout << "A+B+D+C Problem" << endl;
    //     cout << "A+C+B+D Problem" << endl;
    //     cout << "A+C+D+B Problem" << endl;
    //     cout << "A+D+B+C Problem" << endl;
    //     cout << "A+D+C+B Problem" << endl;
    //     cout << "B+A+C+D Problem" << endl;
    //     cout << "B+A+D+C Problem" << endl;
    //     cout << "B+C+A+D Problem" << endl;
    //     cout << "B+C+D+A Problem" << endl;
    //     cout << "B+D+A+C Problem" << endl;
    //     cout << "B+D+C+A Problem" << endl;
    //     cout << "C+A+B+D Problem" << endl;
    //     cout << "C+A+D+B Problem" << endl;
    //     cout << "C+B+A+D Problem" << endl;
    //     cout << "C+B+D+A Problem" << endl;
    //     cout << "C+D+A+B Problem" << endl;
    //     cout << "C+D+B+A Problem" << endl;
    //     cout << "D+A+B+C Problem" << endl;
    //     cout << "D+A+C+B Problem" << endl;
    //     cout << "D+B+A+C Problem" << endl;
    //     cout << "D+B+C+A Problem" << endl;
    //     cout << "D+C+A+B Problem" << endl;
    //     cout << "D+C+B+A Problem" << endl;
    // }
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    do
    {
        for(int i = 0; i < n; i++)
        {
            cout << char('A'+a[i]);
            if(i + 1 != n)
            {
                cout << "+";
            }
        }
        cout << " Problem\n";
    } while (next_permutation(a.begin(), a.end()));
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}