// #include <bits/stdc++.h>
// void solve()
// {
//     std::string s;
//     std::cin >> s;
//     int tt = s.length();
//     if( tt == 1)
//     {
//         char d = s[0] + 1;
//         s += d;
//         std::cout << s << "\n"; 
//         return;
//     }   
//     for(int i = 0; i < tt-1; i++)
//     {
//         if(s[i] == s[i+1])
//         {
//             s.insert(i+1, 1, s[i] + 1);
//         }
//     }
//     if(s.length() == tt)
//     {
//         char c = s[tt-1] + 1;
//         s += c;
//     }
//     std::cout << s << "\n";
// }
// int main()
// {
//     int t;
//     std::cin >> t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int fl = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == s[i+1])
            {
                for(int j = 0; j <= i; j++)
                {
                    cout << s[j];
                }
                cout << char((s[i] - 'a' + 1) % 26 + 'a');
                for(int j = i + 1; j < n; j++)
                {
                    cout << s[j];
                }
                puts("");
                fl = 1;
                break;
            }
        }
        if(!fl)
        {
            cout << char((s[0] - 'a' + 1)%26 + 'a') << s << endl;
        }
    }
    return 0;
}