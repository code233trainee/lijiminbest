#include <bits/stdc++.h>
using namespace std;
// struct KMP{
//     vector<int> nxt;
//     int n;
//     KMP(){
//         n=0;
//     }
//     KMP(string s){
//         int j=0;n=s.size();
//         nxt.resize(n+1);
//         // rep(2,n-1,i)
//         for(int i = 2; i < n-1; i++)
//         {
//             while(j&&s[j+1]!=s[i])
//             {
//                 j=nxt[j];
//             }
//             if(s[j+1]==s[i])
//             {
//                 j++;
//             }
//             nxt[i]=j;
//         }
//     }
// };
vector<int> kmp(string s) {
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
 }
int main()
{
    string s = "ababc";
    vector<int> f = kmp(s);
    for(auto z : f)
    {
        cout << z << " ";
    }
    return 0;
}