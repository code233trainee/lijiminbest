#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        
        map<string, int> ma;
        int n = responses.size();
        for(int i = 0; i < n; i++)
        {
            set<string> se;
            for(int j = 0; j < responses[i].size(); j++)
            {
                se.insert(responses[i][j]);
            }
            for(auto &z : se)
            {
                ma[z]++;
            }
        }
        int mx = 0;
        string s;
        for(auto &z : ma)
        {
            if(z.second >= mx)
            {
                if(z.second == mx)
                {
                    if(z.first < s)
                    {
                        mx = z.second;
                        s = z.first; 
                    }
                }
                else
                {
                    mx = z.second;
                    s = z.first;
                }
            }
        }
        return s;
    }
};
int main()
{
    return 0;
}