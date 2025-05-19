#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFreqSum(string s) {
        int mxY = 0;
        int mxF = 0;
        int n = s.size();
        vector<int> a(26);
        for(int i = 0; i < n; i++)
        {
            a[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
            {
                mxY = max(mxY, a[i]);
            }
            else
            {
                mxF = max(mxF, a[i]);
            }
        }
        return mxY + mxF;
    }
};