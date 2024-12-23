#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a(26);
    for(int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                a[s[i]-'A']++;
            }
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i < 26; i++)
    {
        if(a[i] > mx)
        {
            mx = a[i];
        }
    }
    for(int k = 0; k < mx; k++)
    {
        for(int i = 0; i < 26; i++)
        {
            if(i == 25)
            {
                if(a[i] + k >= mx)
                {   
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }    
                break;
            }
            if(a[i] + k >= mx)
            {   
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    return 0;
}